.setcpu "65816"
.segment "CODE"
.org $3EEC
map_control_0c3eec:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
