.setcpu "65816"
.segment "CODE"
.org $80F9
map_control_0d80f9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
