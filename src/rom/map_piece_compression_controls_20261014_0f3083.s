.setcpu "65816"
.segment "CODE"
.org $3083
map_control_0f3083:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
