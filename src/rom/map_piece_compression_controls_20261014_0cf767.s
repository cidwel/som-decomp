.setcpu "65816"
.segment "CODE"
.org $F767
map_control_0cf767:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
