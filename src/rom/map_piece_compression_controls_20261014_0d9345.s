.setcpu "65816"
.segment "CODE"
.org $9345
map_control_0d9345:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
