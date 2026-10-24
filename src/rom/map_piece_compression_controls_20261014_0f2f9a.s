.setcpu "65816"
.segment "CODE"
.org $2F9A
map_control_0f2f9a:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
