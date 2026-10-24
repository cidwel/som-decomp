.setcpu "65816"
.segment "CODE"
.org $FE03
map_control_0efe03:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
