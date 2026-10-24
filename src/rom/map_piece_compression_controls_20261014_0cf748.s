.setcpu "65816"
.segment "CODE"
.org $F748
map_control_0cf748:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
