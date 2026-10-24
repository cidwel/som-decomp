.setcpu "65816"
.segment "CODE"
.org $B085
map_control_0db085:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
