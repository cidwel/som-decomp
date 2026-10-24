.setcpu "65816"
.segment "CODE"
.org $5565
map_control_0c5565:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
