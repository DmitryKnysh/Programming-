package sample;

import javafx.beans.property.SimpleStringProperty;

public class User {

    private final SimpleStringProperty FROM = new SimpleStringProperty("");
    private final SimpleStringProperty TO = new SimpleStringProperty("");
    private final SimpleStringProperty DATE = new SimpleStringProperty("");
    private final SimpleStringProperty TIME = new SimpleStringProperty("");
    private final SimpleStringProperty DURATION = new SimpleStringProperty("");

    public User() {
        this("", "", "", "", "");
    }

    public User(String FROM, String TO, String DATE,String TIME,String DURATION) {
        setFROM(FROM);
        setTO(TO);
        setDATA(DATE);
        setTIME(TIME);
        setDURATION(DURATION);
    }

    public String getFROM() {
        return FROM.get();
    }

    public void setFROM(String fName) {
        FROM.set(fName);
    }

    public String getTO() {
        return TO.get();
    }

    public void setTO(String fName) {
        TO.set(fName);
    }

    public String getDATA() {
        return DATE.get();
    }

    public void setDATA(String fName) {
        DATE.set(fName);
    }
    public String getTIME() {
        return TIME.get();
    }

    public void setTIME(String fName) {
        TIME.set(fName);
    }
    public String getDURATION() {
        return DURATION.get();
    }

    public void setDURATION(String fName) {
        DURATION.set(fName);
    }
}