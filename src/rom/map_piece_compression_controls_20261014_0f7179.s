.setcpu "65816"
.segment "CODE"
.org $7179
map_control_0f7179:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
