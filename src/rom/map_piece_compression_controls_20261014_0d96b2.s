.setcpu "65816"
.segment "CODE"
.org $96B2
map_control_0d96b2:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
