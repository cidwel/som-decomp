.setcpu "65816"
.segment "CODE"
.org $EE09
map_control_0eee09:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
