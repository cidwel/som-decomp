.setcpu "65816"
.segment "CODE"
.org $603E
map_control_0f603e:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
