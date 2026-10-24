.setcpu "65816"
.segment "CODE"
.org $6F4F
map_control_0c6f4f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
