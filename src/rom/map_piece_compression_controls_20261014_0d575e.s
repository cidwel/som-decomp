.setcpu "65816"
.segment "CODE"
.org $575E
map_control_0d575e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
