.setcpu "65816"
.segment "CODE"
.org $9AA2
map_control_0d9aa2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
