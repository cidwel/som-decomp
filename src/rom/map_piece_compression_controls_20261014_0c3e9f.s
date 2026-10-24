.setcpu "65816"
.segment "CODE"
.org $3E9F
map_control_0c3e9f:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
