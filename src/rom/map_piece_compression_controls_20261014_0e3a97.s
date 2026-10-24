.setcpu "65816"
.segment "CODE"
.org $3A97
map_control_0e3a97:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
