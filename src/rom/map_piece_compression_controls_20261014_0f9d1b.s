.setcpu "65816"
.segment "CODE"
.org $9D1B
map_control_0f9d1b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
