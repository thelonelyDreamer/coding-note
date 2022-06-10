## 一、TypeScript 版本

### 1.1 ref()

作用：定义基本数据类型的响应数据,对象数组也可以用ref

注意点： 插值表达式可以直接取值，setup 内调用则需要.value

```typescript
const str:string = ref("")
const num:number = ref(0)
const isTure:boolean = ref(true)
```

### 1.2 reactive()

作用： 定义对象类型的响应数据

注意点：插值表达式可以直接取值，setup也可以直接调用

```typescript
const obj = reactive({
    str:string,
    num:number,
    isTure:boolean,
})
```

### 1.3 computed()

作用:定义计算属性

```typescript
const matchNames = computed(() => {
  const result = names.value.filter((item) => { 
    return item.name.includes(search.value) 
  })
  return result;
})
```

### 1.4
