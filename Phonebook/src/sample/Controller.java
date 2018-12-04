package sample;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;

public class Controller {
    @FXML private TableView<User> tableView;
    @FXML private TextField FROM;
    @FXML private TextField TO;
    @FXML private TextField DATA;
    @FXML private TextField TIME;
    @FXML private TextField DURATION;
    
    @FXML
    protected void addPerson(ActionEvent event) {
        ObservableList<User> data = tableView.getItems();
        data.add(new User(FROM.getText(),
                TO.getText(),
                DATA.getText(),
                TIME.getText(),
                DURATION.getText()
        ));
        
        FROM.setText("");
        TO.setText("");
        DATA.setText("");
        TIME.setText("");
        DURATION.setText("");
    }
}