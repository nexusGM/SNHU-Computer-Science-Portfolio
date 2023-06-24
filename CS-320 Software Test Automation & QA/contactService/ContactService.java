package contactService;

import java.util.HashMap;
import java.util.Map;

public class ContactService {
	private Map<String, Contact> contacts;

    public ContactService() {
        this.contacts = new HashMap<>();
    }

    public void addContact(Contact contact) {
        String contactId = contact.getContactId();
        contacts.put(contactId, contact);
    }

    public void deleteContact(String contactId) {
        contacts.remove(contactId);
    }

    public void updateContactField(String contactId, String fieldName, String fieldValue) {
        Contact contact = contacts.get(contactId);
        if (contact != null) {
            switch (fieldName.toLowerCase()) {
                case "firstname":
                    contact.setFirstName(fieldValue);
                    break;
                case "lastname":
                    contact.setLastName(fieldValue);
                    break;
                case "phone":
                    contact.setPhone(fieldValue);
                    break;
                case "address":
                    contact.setAddress(fieldValue);
                    break;
                default:
                    System.out.println("Invalid field name: " + fieldName);
                    break;
            }
        }
    }
    
    public Contact getContact(String contactId) {
        return contacts.get(contactId);
    }
    
}
