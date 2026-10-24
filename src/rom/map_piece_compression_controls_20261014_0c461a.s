.setcpu "65816"
.segment "CODE"
.org $461A
map_control_0c461a:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
