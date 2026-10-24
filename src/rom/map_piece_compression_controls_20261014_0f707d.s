.setcpu "65816"
.segment "CODE"
.org $707D
map_control_0f707d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
