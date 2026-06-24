import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import com.infy.linkedIn.entity.Connection;
import com.infy.linkedIn.entity.ConnectionStatus;
import com.infy.linkedIn.exception.ConnectionException;

import java.util.List;
import com.infy.linkedIn.dto.ApiResponseDTO;
import com.infy.linkedIn.dto.ConnectionRequestDTO;
import com.infy.linkedIn.service.ConnectionServiceImpl;

import jakarta.validation.Valid;

@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/api/network")
@Validated
public class ConnectionController {
	
	@Autowired
	private ConnectionServiceImpl connectionService;
	 @GetMapping("/user/{userId}")
    public ResponseEntity<ApiResponseDTO<List<Connection>>> getAllConnections(@PathVariable Long userId) {
        List<Connection> connections = connectionService.getAllConnectionsByUserId(userId);
        
        ApiResponseDTO<List<Connection>> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connections retrieved successfully",
            connections,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Get all received connection invites (pending requests)
     */
    @GetMapping("/user/{userId}/received")
    public ResponseEntity<ApiResponseDTO<List<Connection>>> getReceivedInvites(@PathVariable Long userId) {
        List<Connection> invites = connectionService.getReceivedInvites(userId);
        
        ApiResponseDTO<List<Connection>> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Received invites retrieved successfully",
            invites,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Get all sent connection invites (pending requests)
     */
    @GetMapping("/user/{userId}/sent")
    public ResponseEntity<ApiResponseDTO<List<Connection>>> getSentInvites(@PathVariable Long userId) {
        List<Connection> invites = connectionService.getSentInvites(userId);
        
        ApiResponseDTO<List<Connection>> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Sent invites retrieved successfully",
            invites,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Create a new connection request
     * @throws ConnectionException 
     */
    @PostMapping
    public ResponseEntity<ApiResponseDTO<Connection>> createConnection(@Valid @RequestBody ConnectionRequestDTO requestDTO) throws ConnectionException {
        Connection connection = connectionService.createConnection(requestDTO);
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.CREATED.value(),
            "Connection request sent successfully",
            connection,
            true
        );
        
        return ResponseEntity.status(HttpStatus.CREATED).body(response);
    }
    
    /**
     * Update connection status (accept, ignore, withdraw)
     * @throws ConnectionException 
     */
    @PatchMapping("/{connectionId}/status")
    public ResponseEntity<ApiResponseDTO<Connection>> updateConnectionStatus(
            @PathVariable Long connectionId,
            @RequestParam ConnectionStatus status,
            @RequestParam Long userId) throws ConnectionException {
        Connection updatedConnection = connectionService.updateConnectionStatus(connectionId, status, userId);
        
        String message = switch (status) {
            case ACCEPTED -> "Connection accepted successfully";
            case IGNORED -> "Connection ignored successfully";
            case WITHDRAWN -> "Connection withdrawn successfully";
            default -> "Connection status updated successfully";
        };
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            message,
            updatedConnection,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Accept a connection request
     * @throws ConnectionException 
     */
    @PostMapping("/{connectionId}/accept")
    public ResponseEntity<ApiResponseDTO<Connection>> acceptConnection(
            @PathVariable Long connectionId,
            @RequestParam Long userId) throws ConnectionException {
        Connection connection = connectionService.updateConnectionStatus(
                connectionId, ConnectionStatus.ACCEPTED, userId);
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connection accepted successfully",
            connection,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Ignore a connection request
     * @throws ConnectionException 
     */
    @PostMapping("/{connectionId}/ignore")
    public ResponseEntity<ApiResponseDTO<Connection>> ignoreConnection(
            @PathVariable Long connectionId,
            @RequestParam Long userId) throws ConnectionException {
        Connection connection = connectionService.updateConnectionStatus(
                connectionId, ConnectionStatus.IGNORED, userId);
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connection ignored successfully",
            connection,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Withdraw a connection request (allows re-connection)
     * @throws ConnectionException 
     */
    @PostMapping("/{connectionId}/withdraw")
    public ResponseEntity<ApiResponseDTO<Connection>> withdrawConnection(
            @PathVariable Long connectionId,
            @RequestParam Long userId) throws ConnectionException {
        Connection connection = connectionService.updateConnectionStatus(
                connectionId, ConnectionStatus.WITHDRAWN, userId);
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connection request withdrawn successfully",
            connection,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Get connection by ID
     * @throws ConnectionException 
     */
    @GetMapping("/{connectionId}")
    public ResponseEntity<ApiResponseDTO<Connection>> getConnectionById(@PathVariable Long connectionId) throws ConnectionException {
        Connection connection = connectionService.getConnectionById(connectionId);
        
        ApiResponseDTO<Connection> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connection retrieved successfully",
            connection,
            true
        );
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Delete a connection permanently
     * @throws ConnectionException 
     */
    @DeleteMapping("/{connectionId}")
    public ResponseEntity<ApiResponseDTO<Void>> deleteConnection(
            @PathVariable Long connectionId,
            @RequestParam Long userId) throws ConnectionException {
        connectionService.deleteConnection(connectionId, userId);
        
        ApiResponseDTO<Void> response = new ApiResponseDTO<>(
            HttpStatus.OK.value(),
            "Connection deleted successfully",
            null,
            true
        );
        
        return ResponseEntity.ok(response);
    }
	
}