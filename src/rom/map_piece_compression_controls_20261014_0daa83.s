.setcpu "65816"
.segment "CODE"
.org $AA83
map_control_0daa83:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
