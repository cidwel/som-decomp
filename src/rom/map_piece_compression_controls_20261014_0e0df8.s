.setcpu "65816"
.segment "CODE"
.org $0DF8
map_control_0e0df8:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
