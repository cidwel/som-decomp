.setcpu "65816"
.segment "CODE"
.org $6C51
map_control_0c6c51:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
