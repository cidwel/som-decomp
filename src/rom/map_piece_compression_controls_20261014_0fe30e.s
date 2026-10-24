.setcpu "65816"
.segment "CODE"
.org $E30E
map_control_0fe30e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
