.setcpu "65816"
.segment "CODE"
.org $63E1
map_control_0c63e1:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
