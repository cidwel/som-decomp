.setcpu "65816"
.segment "CODE"
.org $67B1
map_control_0f67b1:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
