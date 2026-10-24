.setcpu "65816"
.segment "CODE"
.org $AACD
map_control_0eaacd:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
