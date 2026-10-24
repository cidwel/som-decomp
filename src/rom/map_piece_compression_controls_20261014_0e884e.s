.setcpu "65816"
.segment "CODE"
.org $884E
map_control_0e884e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
