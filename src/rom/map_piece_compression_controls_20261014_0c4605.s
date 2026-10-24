.setcpu "65816"
.segment "CODE"
.org $4605
map_control_0c4605:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
