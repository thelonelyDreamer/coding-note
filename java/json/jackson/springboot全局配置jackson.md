### 1. 全局配置

```java
@Configuration
public class JacksonConfig {
    @Bean
    @Primary
    public ObjectMapper jacksonObjectMapper(Jackson2ObjectMapperBuilder builder) {
        ObjectMapper objectMapper = builder.createXmlMapper(false).build();
        //序列换成json时,将所有的long变成string.因为js中得数字类型不能包含所有的java long值，超过16位后会出现精度丢失
        SimpleModule simpleModule = new SimpleModule();
        simpleModule.addSerializer(Long.class, com.fasterxml.jackson.databind.ser.std.ToStringSerializer.instance);
        simpleModule.addSerializer(Long.TYPE, com.fasterxml.jackson.databind.ser.std.ToStringSerializer.instance);
        objectMapper.registerModule(simpleModule);
        //反序列化的时候如果多了其他属性,不抛出异常
        objectMapper.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        // 设置空值不处理
        objectMapper.setSerializationInclusion(JsonInclude.Include.NON_NULL);
        //日期格式处理
        objectMapper.setDateFormat(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS"));
        return objectMapper;
    }
    // 可以定义其他的序列化对象
}

```

### 2. 测试

```java
@SpringBootTest
class JacksonConfigTest {
    @Autowired
    private ObjectMapper objectMapper;

    @Test
    public void dateSerialize() throws JsonProcessingException {
        Date date = new Date();
        String s = objectMapper.writeValueAsString(date);
        System.out.println(s); //"2022-06-11 02:08:14:166"
        date =null;
        System.out.println(objectMapper.writeValueAsString(date));//null;
        Person shine = new Person("shine");
        System.out.println(objectMapper.writeValueAsString(shine));//{"name":"shine"}
    }

    @Data
    private static class Person{
        private String name;
        private Date date;
        public Person(String name) {
            this.name = name;
        }
    }
}
```
