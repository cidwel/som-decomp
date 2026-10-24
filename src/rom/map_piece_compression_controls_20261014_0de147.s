.setcpu "65816"
.segment "CODE"
.org $E147
map_control_0de147:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
