.setcpu "65816"
.segment "CODE"
.org $ED6D
map_control_0ded6d:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
