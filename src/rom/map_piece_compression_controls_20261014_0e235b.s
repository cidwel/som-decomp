.setcpu "65816"
.segment "CODE"
.org $235B
map_control_0e235b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
