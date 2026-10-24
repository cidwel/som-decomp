.setcpu "65816"
.segment "CODE"
.org $8ABF
map_control_0c8abf:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
