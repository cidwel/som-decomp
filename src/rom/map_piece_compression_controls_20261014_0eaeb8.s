.setcpu "65816"
.segment "CODE"
.org $AEB8
map_control_0eaeb8:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
