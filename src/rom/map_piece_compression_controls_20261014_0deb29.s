.setcpu "65816"
.segment "CODE"
.org $EB29
map_control_0deb29:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
