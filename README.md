# StreamLogger

A looger using stream for esp-idf.

## Requirements

- esp-idf v2.1.1

## Usage

### Print characters

Like this

```
m2d::ESP32::Logger::I << "Hello";
m2d::ESP32::Logger::I << " world"; // Easy to append characters
m2d::ESP32::Logger::I << m2d::ESP32::Logger::endl; // You have to insert `m2d::ESP32::Logger::endl` to print your console.
```

### Change tag

You can change tag string.
Just call `set_tag(std::string tag)` method.

### Output format

Following formats are available in `include/StreamLogger/Logger.h`:

```
static Stream<Error> E; // wrapper of ESP_LOGE
static Stream<Warning> W; // wrapper of ESP_LOGW
static Stream<Info> I; // wrappaer of ESP_LOGI
static Stream<Debug> D; // wrapper of ESP_LOGD
static Stream<Verbose> V; // wrapper of ESP_LOGV
```

### Add your original formatter

1. Implement subclass of `Impl`.
2. Implement `void print(const char *str)` method.
3. Declare as `Stream<OriginalFormat> logger`.

## License

MIT
