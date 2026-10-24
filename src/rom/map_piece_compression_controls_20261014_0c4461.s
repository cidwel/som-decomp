.setcpu "65816"
.segment "CODE"
.org $4461
map_control_0c4461:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
