.setcpu "65816"
.segment "CODE"
.org $3A46
map_control_0e3a46:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
