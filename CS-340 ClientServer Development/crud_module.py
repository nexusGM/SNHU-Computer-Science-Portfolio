from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """
    
    def __init__(self, username, password, host='nv-desktop-services.apporto.com', port=32503, db='AAC', col='animals'):
        """
        Initializes the MongoClient to access the MongoDB databases and collections.
        The configuration is hard-wired for the 'aac' database, the 'animals' collection, 
        and the 'aacuser'. The connection string variables are unique to the individual 
        Apporto environment.
        
        :Connection Variables:
        USER: MongoDB username
        PASS: MongoDB password
        HOST: MongoDB host URL (default set to 'nv-desktop-services.apporto.com')
        PORT: Port number for MongoDB connection (default set to 32503)
        DB: Database name (default set to 'AAC')
        COL: Collection name (default set to 'animals')
        
        :Attributes:
        client: Instance of MongoClient for database connection
        database: Reference to the specified MongoDB database
        collection: Reference to the specified MongoDB collection
        """
       
        
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (username, password, host, port))
        self.database = self.client[db]
        self.collection = self.database[col]

    def create(self, data):
        """
        Inserts a document into the MongoDB database and collection.
        :param data: Dictionary containing key/value pairs
        :return: True if successful insert, else False
        """
        try:
            if data:
                self.collection.insert_one(data)
                return True
            else:
                return False
        except Exception as e:
            print(f"An error occurred: {e}")
            return False

    def read(self, query):
        """
        Queries for documents from the MongoDB database and collection.
        :param query: Dictionary containing key/value lookup pair
        :return: Result in a list if the command is successful, else an empty list.
        """
        try:
            result = self.collection.find(query)
            return list(result)
        except Exception as e:
            print(f"An error occurred: {e}")
            return []

    def update(self, query, data):
        """
        Queries for documents from the MongoDB database then updates the document.
        :param query: Dictionary containing key/value lookup pair
        :param data: Dictionary containing key/value pairs
        :return: The number of objects modified in the collection.
        """
        try:
            updated_results = self.collection.update_many(query, {'$set': data})
            return updated_results.modified_count
        except Exception as e:
            print(f"An error occurred: {e}")
            return 0

    def delete(self, query):
        """
        Queries for documents from the MongoDB database and removes the document.
        :param query: Dictionary containing key/value lookup pair
        :return: The number of objects removed from the collection.
        """
        try:
            deleted_results = self.collection.delete_many(query)
            return deleted_results.deleted_count
        except Exception as e:
            print(f"An error occurred: {e}")
            return 0