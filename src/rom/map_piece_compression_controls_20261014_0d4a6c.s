.setcpu "65816"
.segment "CODE"
.org $4A6C
map_control_0d4a6c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
