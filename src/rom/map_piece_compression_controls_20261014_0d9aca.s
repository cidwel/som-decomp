.setcpu "65816"
.segment "CODE"
.org $9ACA
map_control_0d9aca:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
