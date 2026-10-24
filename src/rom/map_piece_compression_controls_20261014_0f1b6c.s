.setcpu "65816"
.segment "CODE"
.org $1B6C
map_control_0f1b6c:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
