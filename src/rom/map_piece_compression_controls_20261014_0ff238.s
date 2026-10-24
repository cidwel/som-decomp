.setcpu "65816"
.segment "CODE"
.org $F238
map_control_0ff238:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
