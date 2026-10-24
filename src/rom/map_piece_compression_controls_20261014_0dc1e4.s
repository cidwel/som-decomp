.setcpu "65816"
.segment "CODE"
.org $C1E4
map_control_0dc1e4:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
