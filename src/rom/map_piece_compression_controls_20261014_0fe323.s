.setcpu "65816"
.segment "CODE"
.org $E323
map_control_0fe323:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
