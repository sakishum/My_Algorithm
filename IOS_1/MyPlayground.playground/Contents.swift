//: Playground - noun: a place where people can play

import UIKit
var myVariable = 42
myVariable = 50
let myConstant = 42
let imlicitInteger = 70
let imlicitDouble = 70.0
let explicitDouble: Double = 70
let lable = "The width is"
let width = 94
let widthLable = lable + String(width)
//let widthLable = lable + width
let apples = 3
let oranges = 5 // by gashero
let appleSummary = "I have \(apples) apples."
let fruitSummary = "I have \(apples + oranges) pieces of fruit."
// array 数组
var shoppingList = ["catfish", "water", "tulips", "blue paint"]
shoppingList[1] = "bottle of water"
// dictionary 字典
var occupations = [
    "Malcolm":"Captain",
    "Kaylee":":Mechanic",
]
occupations["Jayne"] = "Pblic Relatons"

// 空数组
let emptyArray = []
// 空字典
let emptyDictionary = Dictionary<String, Float>()

let individualScores = [75, 43, 103, 87, 12]
var teamScores = 0
for score in individualScores {
    // 条件必须是布尔表达式， 不能隐含的与 0 比较
    if score > 50 {
        teamScores += 3
    } else {
        teamScores += 1
    }
}
teamScores

// 可选值
var optionalString: String? = "Hello"
optionalString == nil
var testnil: Int64? = nil

var optionalName: String? = nil//"John Appleseed"
var greeting = "Hello"
if let name = optionalName {
    greeting = "Hello, \(name)"
} else {
    greeting = "hello, nil"
}

// switch 支持多种数据以及多种比较，不限制必须是整数和测试相关
// 在执行匹配的情况下，程序会从 switch 跳出，而不是继续执行下一个情况。
// 所以不需要 break 跳出 switch
let vegetable = "red pepper"
switch vegetable {
    case "celery":
        let vegetableComment = "Add some raisins and make ants on a log."
    case "cucumber", "watercress":
        let vegetableComment = "That would make a good tea sandwich."
    // 判断字符串是否有 ”pepper“ 后缀
    case let x where x.hasSuffix("pepper"):
        let vegetableComment = "Is it a spicy \(x)?"
    // 必须要有 default
    default: // by gashero
        let vegetableComment = "Everything tastes good in shop."
}

// for-in 迭代字典中的每个元素，提供一堆名字来使用每个键值对
let interestingNumbers = [
    "Prime":[2,3,5,7,11,13],
    "Fibonacci":[1,1,2,3,5,8],
    "Square":[1,4,9,16,25],
]
var largest = 0
for (kind, numbers) in interestingNumbers {
    for number in numbers {
        if number > largest {
            largest = number
        }
    }
}
largest

// while
var n = 2
while n < 100 {
    n = n * 2
}
n
var m = 2
repeat {
    m *= 2
} while m < 100
m

var firstForLoop = 0
for i in 0...3 {
    firstForLoop += i
}
firstForLoop
var secondForLoop = 0
for var i = 0; i < 3; ++i {
    secondForLoop += 1
}
secondForLoop

// functor
func greet(name:String, day:String) -> String {
    return "Hello \(name), today is \(day)."
}
greet("Bob", day: "Tuesday")

// tuple
func getGasPrices() -> (Double, Double, Double) {
    return (3.59, 3.69, 3.79)
}
getGasPrices()

// 变参
func sumOf(numbers: Int...) -> Int {
    var sum = 0
    for number in numbers {
        sum += number
    }
    return sum
}
sumOf()
sumOf(42, 597, 12)
func avgOf(numbers: Int...) -> Int {
    var sum = 0
    if numbers.count <= 0 {
        return sum
    }
    for number in numbers {
        sum += number
    }
    return sum/numbers.count
}
avgOf()
avgOf(42, 597, 12)
// 内嵌函数
func returnFifteen() -> Int {
    var y = 10
    func add() {
        y += 5
    }
    add()
    return y
}
returnFifteen()
// return func
func makeIncrementer() -> (Int -> Int) {
    func addOne(number:Int) -> Int {
        return 1 + number
    }
    return addOne
}
var increment = makeIncrementer()
increment(7)
// 接受其他函数作为参数
func hasAnyMatches(list:[Int], condition:Int -> Bool) -> Bool {
    for item in list {
        if condition(item) {
            return true
        }
    }
    return false
}
func lessThanTen(number:Int) -> Bool {
    return number < 10
}
var numbers_1 = [20, 19, 7, 12]
hasAnyMatches(numbers_1, condition: lessThanTen)
// 函数实际是闭包的特殊情况, 闭包可以没有名字:
var cs_1 = numbers_1.map({
    (number:Int) -> Int in
    let result = 3*number
    return result
})
cs_1
var cs_2 = numbers_1.map({number in 3*number})
cs_2
//var cs_3 = sort(&numbers_1){$0 > $1}
// class
// 简单的类定义
class Sharpe {
    var numberOfSides = 0
    let color = "Red"       // 常量属性
    func simpleDescription() -> String {
        return "A \(color) sharpe with \(numberOfSides) sides."
    }
}
// 通过在类名加小括号创建类的实例，使用点语法来访问实例的属性和方法:
var sharpe = Sharpe()
sharpe.numberOfSides = 7
var sharpeDescription = sharpe.simpleDescription()
// 带构构造器来创建实例时设置类
class NameSharpe {
    var numberOfSides:Int = 0
    var name:String
    // 构造器的声明跟函数一样， 除了会创建类的实例
    init(name:String) {
        // 注意 self 用于区分 name 属性和 name 参数
        self.name = name
    }
    // 析构函数
    deinit {
    }
    func simpleDescription() -> String {
        return "A Sharpe with \(numberOfSides) sides."
    }
}
// 派生类
class Square:NameSharpe {
    var sideLength: Double
    init(sideLength:Double, name:String) {
        self.sideLength = sideLength
        super.init(name:name)
        numberOfSides = 4
    }
    func area() -> Double {
        return sideLength * sideLength
    }
    // override 重载超类中的实现，而没有 override 会被编译器视作是错误。
    // 编译器也会检查那些没有被重载的方法
    override func simpleDescription() -> String {
        return "A square with sides of length \(sideLength)."
    }
}
let test = Square(sideLength: 5.2, name: "my test square")
test.area()
test.simpleDescription()

// setter, getter
class EquilateralTriangle: NameSharpe {
    var sideLength:Double = 0.0
    init(sideLength:Double, name: String) {
        self.sideLength = sideLength    // 设置属性的值
        super.init(name: name)          // 调用父类的构造器
        numberOfSides = 3               // 改变父类定义的属性值
    }
    // 属性可以有 getter 与 setter
    var perimeter:Double {
    get {
        return 3.0 * sideLength
    }
    set {
        sideLength = newValue / 3.0
    }
    }
    override func simpleDescription() -> String {
        return "An equilateral triangle with sides of length \(sideLength)."
    }
}
var triangle = EquilateralTriangle(sideLength: 3.1, name: "a triangle")
triangle.perimeter
triangle.perimeter = 9.9



















var str = "Hello, playground, haha~"
