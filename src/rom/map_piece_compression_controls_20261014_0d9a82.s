.setcpu "65816"
.segment "CODE"
.org $9A82
map_control_0d9a82:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
