.setcpu "65816"
.segment "CODE"
.org $700E
map_control_0d700e:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
