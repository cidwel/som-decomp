.setcpu "65816"
.segment "CODE"
.org $3861
map_control_0c3861:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
