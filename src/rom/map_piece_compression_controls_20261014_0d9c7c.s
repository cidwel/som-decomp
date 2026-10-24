.setcpu "65816"
.segment "CODE"
.org $9C7C
map_control_0d9c7c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
