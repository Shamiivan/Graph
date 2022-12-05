package a3;

/*Container class for a key-value pair */
public class Entry <K,V>{
    private K key;
    private V value;

    /*Constructors*/

    //Constructor without arguments
    Entry()
    {key = null; value = null;}

    //Constructor with arguments
    public Entry(K key, V value) {
        this.key = key;
        this.value = value;
    }


    //getters and setters
    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }
}