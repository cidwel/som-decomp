.setcpu "65816"
.segment "CODE"
.org $6119
map_control_0e6119:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
