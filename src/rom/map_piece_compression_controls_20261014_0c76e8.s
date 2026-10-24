.setcpu "65816"
.segment "CODE"
.org $76E8
map_control_0c76e8:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
