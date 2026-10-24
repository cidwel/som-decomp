.setcpu "65816"
.segment "CODE"
.org $A777
map_control_0fa777:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
