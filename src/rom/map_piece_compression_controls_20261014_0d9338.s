.setcpu "65816"
.segment "CODE"
.org $9338
map_control_0d9338:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
