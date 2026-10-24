.setcpu "65816"
.segment "CODE"
.org $EDEA
map_control_0fedea:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
