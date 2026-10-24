.setcpu "65816"
.segment "CODE"
.org $2E0A
map_control_0f2e0a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
