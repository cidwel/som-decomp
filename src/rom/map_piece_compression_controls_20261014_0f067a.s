.setcpu "65816"
.segment "CODE"
.org $067A
map_control_0f067a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
