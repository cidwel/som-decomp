.setcpu "65816"
.segment "CODE"
.org $AD06
map_control_0ead06:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
