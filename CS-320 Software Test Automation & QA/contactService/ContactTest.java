package contactService;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ContactTest {
	
    @Test
    public void testValidContact() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act
        Contact contact = new Contact(contactId, firstName, lastName, phone, address);

        // Assert
        Assertions.assertEquals(contactId, contact.getContactId());
        Assertions.assertEquals(firstName, contact.getFirstName());
        Assertions.assertEquals(lastName, contact.getLastName());
        Assertions.assertEquals(phone, contact.getPhone());
        Assertions.assertEquals(address, contact.getAddress());
    }

    @Test
    public void testInvalidContactId_Null() {
        // Arrange
        String contactId = null;
        String firstName = "John";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }

    @Test
    public void testInvalidContactId_TooLong() {
        // Arrange
        String contactId = "12345678901";
        String firstName = "John";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidFirstName_TooLong() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "JohnJohnJohn";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidFirstName_Null() {
        // Arrange
        String contactId = "1234567890";
        String firstName = null;
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidLastName_TooLong() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "DoeDoeDoeDoe";
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidLastName_Null() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = null;
        String phone = "1234567890";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidPhone_TooLong() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "Doe";
        String phone = "12345678901";
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidPhone_Null() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "Doe";
        String phone = null;
        String address = "123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidAddress_TooLong() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = "123 Main St123 Main St123 Main St";

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }
    
    @Test
    public void testInvalidAddress_Null() {
        // Arrange
        String contactId = "1234567890";
        String firstName = "John";
        String lastName = "Doe";
        String phone = "1234567890";
        String address = null;

        // Act & Assert
        Assertions.assertThrows(IllegalArgumentException.class, () -> {
            new Contact(contactId, firstName, lastName, phone, address);
        });
    }

}
