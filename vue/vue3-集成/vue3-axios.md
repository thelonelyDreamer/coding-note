安装axios

配置axios

```typescript
import axios from "axios";

let config = {

}

const client = axios.create(config)


client.interceptors.request.use(
    function (config) {
        // Do something before request is sent
        return config;
    },
    function (error) {
        // Do something with request error
        return Promise.reject(error);
    }
);

// Add a response interceptor
client.interceptors.response.use(
    function (response) {
        // Do something with response data
        return response;
    },
    function (error) {
        // Do something with response error
        return Promise.reject(error);
    }
);

export default {
    install: function (app: any, options: any) {
        // 添加全局的方法
        app.config.globalProperties.axios = client;
        // 添加全局的方法
        app.config.globalProperties.$translate = (key: any) => {
            return key
        }
    }
}
```

全局引入

```typescript
import axios from './utils/index'

app.use(axios)
```
