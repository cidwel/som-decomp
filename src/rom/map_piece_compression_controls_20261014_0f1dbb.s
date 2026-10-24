.setcpu "65816"
.segment "CODE"
.org $1DBB
map_control_0f1dbb:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
