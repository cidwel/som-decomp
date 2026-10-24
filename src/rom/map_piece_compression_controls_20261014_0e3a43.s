.setcpu "65816"
.segment "CODE"
.org $3A43
map_control_0e3a43:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
