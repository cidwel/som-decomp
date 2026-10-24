.setcpu "65816"
.segment "CODE"
.org $63CE
map_control_0c63ce:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
