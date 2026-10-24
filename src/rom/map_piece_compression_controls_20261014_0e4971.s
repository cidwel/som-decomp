.setcpu "65816"
.segment "CODE"
.org $4971
map_control_0e4971:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
