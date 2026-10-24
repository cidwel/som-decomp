.setcpu "65816"
.segment "CODE"
.org $A430
map_control_0fa430:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
