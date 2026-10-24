.setcpu "65816"
.segment "CODE"
.org $6C2F
map_control_0f6c2f:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
