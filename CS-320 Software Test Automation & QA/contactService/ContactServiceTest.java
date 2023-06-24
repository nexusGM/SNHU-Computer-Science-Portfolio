package contactService;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ContactServiceTest {
    private ContactService contactService;

    @BeforeEach
    public void setUp() {
        contactService = new ContactService();
    }

    @Test
    public void testAddContact() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");

        // Act
        contactService.addContact(contact);

        // Assert
        Contact retrievedContact = contactService.getContact("001");
        Assertions.assertNotNull(retrievedContact);
        Assertions.assertEquals(contact, retrievedContact);
    }

    @Test
    public void testDeleteContact() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);

        // Act
        contactService.deleteContact("001");

        // Assert
        Contact retrievedContact = contactService.getContact("001");
        Assertions.assertNull(retrievedContact);
    }

    @Test
    public void testUpdateFirstName() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);

        // Act
        contactService.updateContactField("001", "firstName", "Jane");

        // Assert
        Contact updatedContact = contactService.getContact("001");
        Assertions.assertNotNull(updatedContact);
        Assertions.assertEquals("Jane", updatedContact.getFirstName());
    }

    @Test
    public void testUpdateLastName() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);

        // Act
        contactService.updateContactField("001", "lastName", "Smith");

        // Assert
        Contact updatedContact = contactService.getContact("001");
        Assertions.assertNotNull(updatedContact);
        Assertions.assertEquals("Smith", updatedContact.getLastName());
    }

    @Test
    public void testUpdatePhone() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);

        // Act
        contactService.updateContactField("001", "phone", "9876543210");

        // Assert
        Contact updatedContact = contactService.getContact("001");
        Assertions.assertNotNull(updatedContact);
        Assertions.assertEquals("9876543210", updatedContact.getPhone());
    }

    @Test
    public void testUpdateAddress() {
        // Arrange
        Contact contact = new Contact("001", "John", "Doe", "1234567890", "123 Main St");
        contactService.addContact(contact);

        // Act
        contactService.updateContactField("001", "address", "456 Elm St");

        // Assert
        Contact updatedContact = contactService.getContact("001");
        Assertions.assertNotNull(updatedContact);
        Assertions.assertEquals("456 Elm St", updatedContact.getAddress());
    }
}
