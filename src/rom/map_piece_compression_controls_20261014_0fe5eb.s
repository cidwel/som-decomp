.setcpu "65816"
.segment "CODE"
.org $E5EB
map_control_0fe5eb:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
