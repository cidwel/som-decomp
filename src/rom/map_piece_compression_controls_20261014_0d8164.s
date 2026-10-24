.setcpu "65816"
.segment "CODE"
.org $8164
map_control_0d8164:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
