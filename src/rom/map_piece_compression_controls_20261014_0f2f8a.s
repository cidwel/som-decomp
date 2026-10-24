.setcpu "65816"
.segment "CODE"
.org $2F8A
map_control_0f2f8a:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
