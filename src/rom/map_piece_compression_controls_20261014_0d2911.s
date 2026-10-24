.setcpu "65816"
.segment "CODE"
.org $2911
map_control_0d2911:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
