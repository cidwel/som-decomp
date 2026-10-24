.setcpu "65816"
.segment "CODE"
.org $AAC5
map_control_0faac5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
