.setcpu "65816"
.segment "CODE"
.org $02AB
map_control_0e02ab:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
