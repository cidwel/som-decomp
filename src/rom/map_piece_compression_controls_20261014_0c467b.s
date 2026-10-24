.setcpu "65816"
.segment "CODE"
.org $467B
map_control_0c467b:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
