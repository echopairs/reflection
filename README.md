# reflection
 **Des:** 根据类名的字符串来构造对应类的对象。
 **背景:** 项目中接收到数据的格式为 topic + message 。需要通过topic来序列化message
 
 ## 思路
 1). 一个message生产类，其中提供一个接口，传入topic,返回message的对象
 
 2). 因为对于同一种类型的message，可能需要构造多次该message，所以生产类中存放的的是消息构造器，而不是具体的资源
 
 3). 为了保证程序中调用获取消息接口的人正确，所以消息构造器应该在程序运行前已经完成注册。
 
 4). 为了实现3中的要求，可以提供一个消息辅助构造类(在辅助构造类的构造函数注册),利用static 全局变量在程序运行前已经完成初始化，实现注册
 
 5). 通过宏展开来简化代码(宏展开在预编译阶，构造一个静态全局变量)
 
 ## 核心代码
 ```
 class AutoFactory
 {
    public:
    template<typename  T>
    class RegisterHelper
    {
    public:
        // 消息辅助类
        RegisterHelper(const std::string &type_name)
        {
            AutoFactory::Instance().maps_.emplace(type_name, [] { return new T(); });
        }
       
       // 对外提供的接口
       static Message* GetMessage(const std::string type_name)
       {
          auto item = maps_.find(type_name);
          if (item == maps_.end())
          {
            return nullptr;
          }
          return maps_[type_name]();
       }
        
    private:

    static std::map<std::string, std::function<Message*()> > maps_;  // key: type_name, value: produce function
 }；
 #define REGISTER_MESSAGE(T, key)  \
static AutoFactory::RegisterHelper<T> T##message (key)
 ```
