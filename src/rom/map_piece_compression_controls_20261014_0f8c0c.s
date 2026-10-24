.setcpu "65816"
.segment "CODE"
.org $8C0C
map_control_0f8c0c:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
