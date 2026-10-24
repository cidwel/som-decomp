.setcpu "65816"
.segment "CODE"
.org $6CCC
map_control_0d6ccc:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
