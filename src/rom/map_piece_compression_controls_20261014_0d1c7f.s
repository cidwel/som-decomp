.setcpu "65816"
.segment "CODE"
.org $1C7F
map_control_0d1c7f:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
