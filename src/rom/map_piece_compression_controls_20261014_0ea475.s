.setcpu "65816"
.segment "CODE"
.org $A475
map_control_0ea475:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
