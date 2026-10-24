.setcpu "65816"
.segment "CODE"
.org $372C
map_control_0f372c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
