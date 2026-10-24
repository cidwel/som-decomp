.setcpu "65816"
.segment "CODE"
.org $917B
map_control_0c917b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
