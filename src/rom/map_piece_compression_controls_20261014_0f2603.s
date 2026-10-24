.setcpu "65816"
.segment "CODE"
.org $2603
map_control_0f2603:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
