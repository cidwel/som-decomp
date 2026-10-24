.setcpu "65816"
.segment "CODE"
.org $A45B
map_control_0ea45b:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
