.setcpu "65816"
.segment "CODE"
.org $5203
map_control_0c5203:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
