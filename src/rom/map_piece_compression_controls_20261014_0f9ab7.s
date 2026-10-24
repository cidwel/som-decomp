.setcpu "65816"
.segment "CODE"
.org $9AB7
map_control_0f9ab7:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
