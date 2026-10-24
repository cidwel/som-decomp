.setcpu "65816"
.segment "CODE"
.org $4491
map_control_0d4491:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
