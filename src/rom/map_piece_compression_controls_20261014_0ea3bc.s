.setcpu "65816"
.segment "CODE"
.org $A3BC
map_control_0ea3bc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
