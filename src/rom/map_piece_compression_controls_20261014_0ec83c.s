.setcpu "65816"
.segment "CODE"
.org $C83C
map_control_0ec83c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
