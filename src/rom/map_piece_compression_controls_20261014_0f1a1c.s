.setcpu "65816"
.segment "CODE"
.org $1A1C
map_control_0f1a1c:
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
