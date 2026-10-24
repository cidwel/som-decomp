.setcpu "65816"
.segment "CODE"
.org $9232
map_control_0d9232:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
