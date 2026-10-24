.setcpu "65816"
.segment "CODE"
.org $7D6B
map_control_0d7d6b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
