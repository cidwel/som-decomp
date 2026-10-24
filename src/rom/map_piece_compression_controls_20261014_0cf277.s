.setcpu "65816"
.segment "CODE"
.org $F277
map_control_0cf277:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
