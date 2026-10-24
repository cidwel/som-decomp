.setcpu "65816"
.segment "CODE"
.org $AD36
map_control_0fad36:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
