.setcpu "65816"
.segment "CODE"
.org $39F3
map_control_0c39f3:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
