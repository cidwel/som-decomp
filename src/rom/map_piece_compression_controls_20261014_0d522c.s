.setcpu "65816"
.segment "CODE"
.org $522C
map_control_0d522c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
