.setcpu "65816"
.segment "CODE"
.org $917A
map_control_0f917a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
