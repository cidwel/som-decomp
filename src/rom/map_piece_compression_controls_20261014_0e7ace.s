.setcpu "65816"
.segment "CODE"
.org $7ACE
map_control_0e7ace:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
