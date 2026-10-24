.setcpu "65816"
.segment "CODE"
.org $CF55
map_control_0ecf55:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
