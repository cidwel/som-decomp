.setcpu "65816"
.segment "CODE"
.org $F7CF
map_control_0df7cf:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
