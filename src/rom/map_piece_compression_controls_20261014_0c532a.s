.setcpu "65816"
.segment "CODE"
.org $532A
map_control_0c532a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
