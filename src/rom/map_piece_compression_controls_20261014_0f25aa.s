.setcpu "65816"
.segment "CODE"
.org $25AA
map_control_0f25aa:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
