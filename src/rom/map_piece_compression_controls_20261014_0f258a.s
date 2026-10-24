.setcpu "65816"
.segment "CODE"
.org $258A
map_control_0f258a:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
