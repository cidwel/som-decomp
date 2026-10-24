.setcpu "65816"
.segment "CODE"
.org $F125
map_control_0df125:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
