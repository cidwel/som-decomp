.setcpu "65816"
.segment "CODE"
.org $9D7C
map_control_0f9d7c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
