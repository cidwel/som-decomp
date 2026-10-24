.setcpu "65816"
.segment "CODE"
.org $3E88
map_control_0c3e88:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
