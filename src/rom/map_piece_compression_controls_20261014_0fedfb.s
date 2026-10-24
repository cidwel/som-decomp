.setcpu "65816"
.segment "CODE"
.org $EDFB
map_control_0fedfb:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
