### 1.ObjectMapper是线程安全的吗

> 1. 如果直接使用ObjectMapper，需要在第一次使用前做好配置，后面并发使用是线程安全的。但是如果要做配置变更，则可能会报错。
> 
> 2. 可以直接使用ObjectReader或者ObjectWriter，这两个一旦通过ObjectMapper创建完后就是完全不可变更的。
