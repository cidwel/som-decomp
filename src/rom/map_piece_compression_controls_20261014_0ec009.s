.setcpu "65816"
.segment "CODE"
.org $C009
map_control_0ec009:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
