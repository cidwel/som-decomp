.setcpu "65816"
.segment "CODE"
.org $EF15
map_control_0def15:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
