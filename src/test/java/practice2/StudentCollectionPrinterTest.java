package practice2;

import org.junit.Test;

import java.lang.reflect.Field;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collection;

public class StudentCollectionPrinterTest {
    @Test
    public void testPrint() throws Exception {
        Collection<Student> students = new ArrayList<>();
        Student student1 = new Student();
        student1.setName("Alice");
        student1.setAge(20);
        student1.setAddress("123 Main St.");
        student1.setDateOfBirth(new SimpleDateFormat("yyyy-MM-dd").parse("2003-01-01"));
        students.add(student1);

        Student student2 = new Student();
        student2.setName("Bob");
        student2.setAge(21);
        student2.setAddress("456 Elm St.");
        student2.setDateOfBirth(new SimpleDateFormat("yyyy-MM-dd").parse("2002-02-02"));
        students.add(student2);

        for (Field field : Student.class.getDeclaredFields()) {
            if (field.getName().equals("name")) {
                field.setAccessible(true);
                field.setAnnotation(StudentField.class, new StudentField() {
                    @Override
                    public String name() {
                        return "姓名";
                    }

                    @Override
                    public Class<? extends Annotation> annotationType() {
                        return StudentField.class;
                    }
                });
            } else if (field.getName().equals("age")) {
                field.setAccessible(true);
                field.setAnnotation(StudentField.class, new StudentField() {
                    @Override
                    public String name() {
                        return "年龄";
                    }

                    @Override
                    public Class<? extends Annotation>

