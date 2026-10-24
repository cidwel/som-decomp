.setcpu "65816"
.segment "CODE"
.org $74B7
map_control_0f74b7:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
