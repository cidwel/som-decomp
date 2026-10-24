.setcpu "65816"
.segment "CODE"
.org $97CC
map_control_0d97cc:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
