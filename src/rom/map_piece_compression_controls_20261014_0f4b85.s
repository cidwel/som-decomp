.setcpu "65816"
.segment "CODE"
.org $4B85
map_control_0f4b85:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
