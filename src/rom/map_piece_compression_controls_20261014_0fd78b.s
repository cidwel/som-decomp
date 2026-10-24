.setcpu "65816"
.segment "CODE"
.org $D78B
map_control_0fd78b:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
