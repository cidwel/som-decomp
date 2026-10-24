.setcpu "65816"
.segment "CODE"
.org $7F5C
map_control_0c7f5c:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
