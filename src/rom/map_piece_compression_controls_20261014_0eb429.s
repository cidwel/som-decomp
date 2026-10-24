.setcpu "65816"
.segment "CODE"
.org $B429
map_control_0eb429:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
