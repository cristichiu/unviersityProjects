function test(start, end) {
    let counter = 0
    for(let i=start; i<=end; i++) {
        console.log(i + ". test")
        counter += i
    }
    return counter
}
console.log(test(0, 10))
