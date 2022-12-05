package a3;

/** Array-based list implementation */
public class List<V> implements ADTList<V> {

    private static final int defaultSize = 10; // Default size
    private int maxSize; // Maximum size of list
    private int listSize; // Current # of list items, length
    private int curr; // Position of current element
    private V[] listArray; // Array holding list elements

    /** Constructors */
    /** Create a list with the default capacity. */
    public List() { this(defaultSize); }

    /** Create a new list object.
     @param size Max # of elements list can contain. */
    @SuppressWarnings("unchecked") // Generic array allocation
    public List(int size) {
        maxSize = size;
        listSize = curr = 0;
        listArray = (V[])new Object[size]; // Create listArray
    }

    /** Reinitialize the list */
    public void clear() {
        listSize = curr = 0;
    } // Simply reinitialize values

    /** Insert "it" at current position */
    public void insert(V it) {

        assert listSize < maxSize : "List capacity exceeded";

        for (int i=listSize; i>curr; i--) // Shift elements up
            listArray[i] = listArray[i-1]; // to make room
        listArray[curr] = it;
        listSize++; // Increment list size
    }

    public void setValue(int pos, V value){
        assert listSize < maxSize : "List capacity exceeded";
        //save curr
        int initPos = curr;
        curr = pos;
        insert(value);
        curr = initPos;
    }

    /** Append "elem" to list */
    public void append(V it) {
        assert listSize < maxSize : "List capacity exceeded";
        listArray[listSize++] = it;
    }

    /** Remove and return the current element */
    public V remove() {
        if ((curr<0) || (curr>=listSize)) // No current element
            return null;
        V it = listArray[curr]; // Copy the element
        for(int i=curr; i<listSize-1; i++) // Shift them down
            listArray[i] = listArray[i+1];
        listSize--; // Decrement size
        return it;
    }

    public void moveToStart() { curr = 0; } // Set to front

    public void moveToEnd() { curr = listSize; } // Set at end

    public void prev() { if (curr != 0) curr--; } // Back up

    public void next() { if (curr < listSize) curr++; }

    public int length() { return listSize; }

    /** @return Current position */
    public int currPos() { return curr; }

    /** Set current list position to "pos" */
    public void moveToPos(int pos) {
        assert (pos>=0) && (pos<=listSize) : "Pos out of range";
        curr = pos;
    }

    /** @return Current element */
    public V getValue() {
        assert (curr>=0) && (curr<listSize) : "No current element";
        return listArray[curr];
    }

    public V getValueAtPos(int pos){
        assert (curr>=0) && (curr<listSize) : "No current element";
        //save initial position
        int initPos = curr;
        moveToPos(pos);
        V temp = getValue();
        moveToPos(initPos);
        return temp;
    }



    public String toString()
    {
        // Save the current position of the list
        int oldPos = currPos();
        int length = length();
        StringBuffer out = new StringBuffer((length() + 1) * 4);

        moveToStart();
        out.append("< ");
        for (int i = 0; i < oldPos; i++) {
            out.append(getValue());
            out.append(" ");
            next();
        }
        out.append("| ");
        for (int i = oldPos; i < length; i++) {
            out.append(getValue());
            out.append(" ");
            next();
        }
        out.append(">");
        moveToPos(oldPos); // Reset the fence to its original position
        return out.toString();
    }

    public V[] toArray(){
        return listArray;
    }

}