.setcpu "65816"
.segment "CODE"
.org $8525
map_control_0e8525:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
