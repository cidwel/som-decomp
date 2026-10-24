.setcpu "65816"
.segment "CODE"
.org $7539
map_control_0f7539:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
