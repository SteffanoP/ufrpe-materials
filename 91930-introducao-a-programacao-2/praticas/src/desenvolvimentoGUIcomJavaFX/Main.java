package desenvolvimentoGUIcomJavaFX;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Main extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Pane p = new Pane();
        p.setPrefHeight(480);
        p.setPrefWidth(640);
        Text a = new Text("Hello World!");
        Scene s = new Scene(p);

        primaryStage.setScene(s);
        primaryStage.show();
    }
}
