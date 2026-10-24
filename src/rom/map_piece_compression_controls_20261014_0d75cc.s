.setcpu "65816"
.segment "CODE"
.org $75CC
map_control_0d75cc:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
