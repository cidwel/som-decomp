.setcpu "65816"
.segment "CODE"
.org $6F31
map_control_0e6f31:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
