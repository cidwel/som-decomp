.setcpu "65816"
.segment "CODE"
.org $EB4C
map_control_0eeb4c:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
