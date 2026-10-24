.setcpu "65816"
.segment "CODE"
.org $6841
map_control_0f6841:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
