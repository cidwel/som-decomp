.setcpu "65816"
.segment "CODE"
.org $7C2A
map_control_0f7c2a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
