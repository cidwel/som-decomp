.setcpu "65816"
.segment "CODE"
.org $77CF
map_control_0d77cf:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
