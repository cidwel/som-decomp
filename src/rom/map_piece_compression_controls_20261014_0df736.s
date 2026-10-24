.setcpu "65816"
.segment "CODE"
.org $F736
map_control_0df736:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
