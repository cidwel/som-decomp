.setcpu "65816"
.segment "CODE"
.org $7B6C
map_control_0c7b6c:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
