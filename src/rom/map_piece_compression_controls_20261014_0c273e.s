.setcpu "65816"
.segment "CODE"
.org $273E
map_control_0c273e:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
