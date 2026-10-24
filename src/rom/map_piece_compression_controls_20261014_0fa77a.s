.setcpu "65816"
.segment "CODE"
.org $A77A
map_control_0fa77a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
