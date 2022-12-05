package a3;

public class DDictionary{
    private List<Entry<Integer, String>> list;
    private int counter;
    /*Constructors*/
    DDictionary(){
        list = new List<>();
    }
    DDictionary(int numItems){
        list = new List<>(numItems);
    }



    public void clear() {list.clear();}

    public void insert(String value) {
        //check if course is already in dictionary
        if(findKey(value) != -1) return;
        else {
            Entry<Integer, String> newEntry = new Entry<>(counter, value);
            list.append(newEntry);
            counter++;
        }
    }



    public String remove(int key) {
        String temp = find(key);
        if(temp != null) list.remove();
        return temp;
    }


    public String removeAny() {
        if(size() != 0){
            list.moveToEnd();
            list.prev();
            Entry<Integer,String> removedEntry = list.remove();
            return removedEntry.getValue();
        }
        else return null;
    }

    //return key given value, if value not found return -1
    public int findKey(String value) {
        Entry<Integer,String> temp = new Entry<>();
        for(list.moveToStart();list.currPos() < list.length(); list.next()){
            temp = list.getValue();
            int key = temp.getKey();
            String _returnVal = temp.getValue();
            if(_returnVal.equals(value)){
                return key;
            }
        }
        //if value is not there
        return -1;
    }
    // Given a key return it's value, else return null
    public String find(int _key) {
        Entry<Integer,String> temp = new Entry<>();
        for(list.moveToStart();list.currPos() < list.length(); list.next()){
            temp = list.getValue();
            int key = temp.getKey();
            if(_key == key){
                return temp.getValue();
            }
        }
        return null;
    }
    public int size() {
        return list.length();
    }

    public int returnKey(String value){
        return findKey(value);
    }

    public String returnValue(int _key){
        return find(_key);
    }

    public void print() {
        Entry<Integer,String> temp = new Entry<>();
        for(list.moveToStart();list.currPos() < list.length(); list.next()){
            temp = list.getValue();
            System.out.println(temp.getKey() + ":  " + temp.getValue());
        }
    }

}