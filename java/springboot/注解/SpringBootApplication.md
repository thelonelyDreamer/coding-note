```java
@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
@Documented
@Inherited
@SpringBootConfiguration
@EnableAutoConfiguration
@ComponentScan(excludeFilters = { @Filter(type = FilterType.CUSTOM, classes = TypeExcludeFilter.class),
        @Filter(type = FilterType.CUSTOM, classes = AutoConfigurationExcludeFilter.class) })
public @interface SpringBootApplication {

    /**
     * Exclude specific auto-configuration classes such that they will never be applied.
     * @return the classes to exclude
     */
    @AliasFor(annotation = EnableAutoConfiguration.class)
    Class<?>[] exclude() default {};

    /**
     * Exclude specific auto-configuration class names such that they will never be
     * applied.
     * @return the class names to exclude
     * @since 1.3.0
     */
    @AliasFor(annotation = EnableAutoConfiguration.class)
    String[] excludeName() default {};

    /**
     * Base packages to scan for annotated components. Use {@link #scanBasePackageClasses}
     * for a type-safe alternative to String-based package names.
     * <p>
     * <strong>Note:</strong> this setting is an alias for
     * {@link ComponentScan @ComponentScan} only. It has no effect on {@code @Entity}
     * scanning or Spring Data {@link Repository} scanning. For those you should add
     * {@link org.springframework.boot.autoconfigure.domain.EntityScan @EntityScan} and
     * {@code @Enable...Repositories} annotations.
     * @return base packages to scan
     * @since 1.3.0
     */
    @AliasFor(annotation = ComponentScan.class, attribute = "basePackages")
    String[] scanBasePackages() default {};

    /**
     * Type-safe alternative to {@link #scanBasePackages} for specifying the packages to
     * scan for annotated components. The package of each class specified will be scanned.
     * <p>
     * Consider creating a special no-op marker class or interface in each package that
     * serves no purpose other than being referenced by this attribute.
     * <p>
     * <strong>Note:</strong> this setting is an alias for
     * {@link ComponentScan @ComponentScan} only. It has no effect on {@code @Entity}
     * scanning or Spring Data {@link Repository} scanning. For those you should add
     * {@link org.springframework.boot.autoconfigure.domain.EntityScan @EntityScan} and
     * {@code @Enable...Repositories} annotations.
     * @return base packages to scan
     * @since 1.3.0
     */
    @AliasFor(annotation = ComponentScan.class, attribute = "basePackageClasses")
    Class<?>[] scanBasePackageClasses() default {};

    /**
     * The {@link BeanNameGenerator} class to be used for naming detected components
     * within the Spring container.
     * <p>
     * The default value of the {@link BeanNameGenerator} interface itself indicates that
     * the scanner used to process this {@code @SpringBootApplication} annotation should
     * use its inherited bean name generator, e.g. the default
     * {@link AnnotationBeanNameGenerator} or any custom instance supplied to the
     * application context at bootstrap time.
     * @return {@link BeanNameGenerator} to use
     * @see SpringApplication#setBeanNameGenerator(BeanNameGenerator)
     * @since 2.3.0
     */
    @AliasFor(annotation = ComponentScan.class, attribute = "nameGenerator")
    Class<? extends BeanNameGenerator> nameGenerator() default BeanNameGenerator.class;

    /**
     * Specify whether {@link Bean @Bean} methods should get proxied in order to enforce
     * bean lifecycle behavior, e.g. to return shared singleton bean instances even in
     * case of direct {@code @Bean} method calls in user code. This feature requires
     * method interception, implemented through a runtime-generated CGLIB subclass which
     * comes with limitations such as the configuration class and its methods not being
     * allowed to declare {@code final}.
     * <p>
     * The default is {@code true}, allowing for 'inter-bean references' within the
     * configuration class as well as for external calls to this configuration's
     * {@code @Bean} methods, e.g. from another configuration class. If this is not needed
     * since each of this particular configuration's {@code @Bean} methods is
     * self-contained and designed as a plain factory method for container use, switch
     * this flag to {@code false} in order to avoid CGLIB subclass processing.
     * <p>
     * Turning off bean method interception effectively processes {@code @Bean} methods
     * individually like when declared on non-{@code @Configuration} classes, a.k.a.
     * "@Bean Lite Mode" (see {@link Bean @Bean's javadoc}). It is therefore behaviorally
     * equivalent to removing the {@code @Configuration} stereotype.
     * @since 2.2
     * @return whether to proxy {@code @Bean} methods
     */
    @AliasFor(annotation = Configuration.class)
    boolean proxyBeanMethods() default true;

}
```

> @SpringBootApplication????????????????????????????????????
> 
> @EnableAutoConfiguration???
> 
> SpringBoot????????????????????????????????????Spring????????????????????????
> 
> @SpringBootConfiguration(?????????@Configuration)???
> 
> ????????????????????????spring???XML???????????????(applicationContext.xml)???????????????bean????????????????????????spring??????????????????
> 
> @ComponentScan???
> 
> ???????????????????????????????????????Bean???????????????SpringApplication???run????????????Booter.class??????????????????????????????????????????????????????????????????????????????
