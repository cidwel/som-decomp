.setcpu "65816"
.segment "CODE"
.org $4643
map_control_0c4643:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
