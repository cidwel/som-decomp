.setcpu "65816"
.segment "CODE"
.org $753D
map_control_0e753d:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
