.setcpu "65816"
.segment "CODE"
.org $B004
map_control_0fb004:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
