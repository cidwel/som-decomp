.setcpu "65816"
.segment "CODE"
.org $789C
map_control_0f789c:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
