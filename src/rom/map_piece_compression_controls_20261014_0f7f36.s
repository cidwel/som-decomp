.setcpu "65816"
.segment "CODE"
.org $7F36
map_control_0f7f36:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
