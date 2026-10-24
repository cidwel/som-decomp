.setcpu "65816"
.segment "CODE"
.org $5ED2
map_control_0f5ed2:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
