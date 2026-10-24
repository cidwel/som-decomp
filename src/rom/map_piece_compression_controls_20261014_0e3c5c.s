.setcpu "65816"
.segment "CODE"
.org $3C5C
map_control_0e3c5c:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
