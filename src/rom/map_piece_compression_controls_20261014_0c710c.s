.setcpu "65816"
.segment "CODE"
.org $710C
map_control_0c710c:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
