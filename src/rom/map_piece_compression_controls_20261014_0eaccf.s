.setcpu "65816"
.segment "CODE"
.org $ACCF
map_control_0eaccf:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
