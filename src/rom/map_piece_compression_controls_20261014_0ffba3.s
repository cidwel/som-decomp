.setcpu "65816"
.segment "CODE"
.org $FBA3
map_control_0ffba3:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
