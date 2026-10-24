.setcpu "65816"
.segment "CODE"
.org $E5DE
map_control_0fe5de:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
