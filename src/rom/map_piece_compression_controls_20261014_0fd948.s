.setcpu "65816"
.segment "CODE"
.org $D948
map_control_0fd948:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
