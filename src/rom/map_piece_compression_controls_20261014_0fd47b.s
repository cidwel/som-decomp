.setcpu "65816"
.segment "CODE"
.org $D47B
map_control_0fd47b:
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
