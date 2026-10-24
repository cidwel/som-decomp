.setcpu "65816"
.segment "CODE"
.org $72EE
map_control_0e72ee:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
