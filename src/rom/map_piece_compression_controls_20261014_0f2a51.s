.setcpu "65816"
.segment "CODE"
.org $2A51
map_control_0f2a51:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
