.setcpu "65816"
.segment "CODE"
.org $4900
map_control_0d4900:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
