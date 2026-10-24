.setcpu "65816"
.segment "CODE"
.org $308B
map_control_0c308b:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
