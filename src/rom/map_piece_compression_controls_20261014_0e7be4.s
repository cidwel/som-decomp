.setcpu "65816"
.segment "CODE"
.org $7BE4
map_control_0e7be4:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
