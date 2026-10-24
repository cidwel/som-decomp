.setcpu "65816"
.segment "CODE"
.org $0E96
map_control_0e0e96:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
