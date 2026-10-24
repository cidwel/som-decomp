.setcpu "65816"
.segment "CODE"
.org $46B8
map_control_0d46b8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
