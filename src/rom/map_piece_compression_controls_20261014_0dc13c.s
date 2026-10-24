.setcpu "65816"
.segment "CODE"
.org $C13C
map_control_0dc13c:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
