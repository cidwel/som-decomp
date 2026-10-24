.setcpu "65816"
.segment "CODE"
.org $7747
map_control_0d7747:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
