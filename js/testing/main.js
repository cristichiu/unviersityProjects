// // width, height, rotation False/True, character
// function drawRect(width, height, rotation, char) {
//     let res = ""
//     char = char[0]
//     if(rotation) {
//         let temp = width
//         width = height
//         height = temp
//     }
//     for(let i=0; i<height; i++) {
//         if(i==0 || i==height-1) {
//             res += char.repeat(width) + "\n"
//         } else {
//             res += char + " ".repeat(width-2) + char + "\n"
//         }
//     }
//     return res
// }
//
// console.log(drawRect(5,10,false,"*"))
// console.log(drawRect(5,10,true,"#"))
