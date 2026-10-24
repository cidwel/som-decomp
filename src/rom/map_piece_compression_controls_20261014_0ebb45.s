.setcpu "65816"
.segment "CODE"
.org $BB45
map_control_0ebb45:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
