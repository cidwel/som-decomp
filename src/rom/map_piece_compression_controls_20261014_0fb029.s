.setcpu "65816"
.segment "CODE"
.org $B029
map_control_0fb029:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
