.setcpu "65816"
.segment "CODE"
.org $8566
map_control_0d8566:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
