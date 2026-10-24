.setcpu "65816"
.segment "CODE"
.org $F1EC
map_control_0df1ec:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
