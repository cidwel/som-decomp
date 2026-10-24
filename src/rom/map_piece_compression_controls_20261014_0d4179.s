.setcpu "65816"
.segment "CODE"
.org $4179
map_control_0d4179:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
