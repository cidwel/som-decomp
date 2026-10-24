.setcpu "65816"
.segment "CODE"
.org $B069
map_control_0fb069:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
