.setcpu "65816"
.segment "CODE"
.org $AD0E
map_control_0ead0e:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
