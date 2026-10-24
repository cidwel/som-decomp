.setcpu "65816"
.segment "CODE"
.org $2E37
map_control_0f2e37:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
