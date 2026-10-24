.setcpu "65816"
.segment "CODE"
.org $45D1
map_control_0c45d1:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
