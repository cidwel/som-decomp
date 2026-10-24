.setcpu "65816"
.segment "CODE"
.org $C719
map_control_0ec719:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
