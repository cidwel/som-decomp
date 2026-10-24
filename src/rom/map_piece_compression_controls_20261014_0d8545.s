.setcpu "65816"
.segment "CODE"
.org $8545
map_control_0d8545:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
