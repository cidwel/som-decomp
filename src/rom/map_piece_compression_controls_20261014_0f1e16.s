.setcpu "65816"
.segment "CODE"
.org $1E16
map_control_0f1e16:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
