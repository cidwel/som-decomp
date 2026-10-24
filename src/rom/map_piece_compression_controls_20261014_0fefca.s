.setcpu "65816"
.segment "CODE"
.org $EFCA
map_control_0fefca:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
