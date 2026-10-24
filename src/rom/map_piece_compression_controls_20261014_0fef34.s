.setcpu "65816"
.segment "CODE"
.org $EF34
map_control_0fef34:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
