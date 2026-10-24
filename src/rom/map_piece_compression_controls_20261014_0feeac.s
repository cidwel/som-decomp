.setcpu "65816"
.segment "CODE"
.org $EEAC
map_control_0feeac:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
