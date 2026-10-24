.setcpu "65816"
.segment "CODE"
.org $3A05
map_control_0c3a05:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
