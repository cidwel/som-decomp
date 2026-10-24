.setcpu "65816"
.segment "CODE"
.org $F2E3
map_control_0cf2e3:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
