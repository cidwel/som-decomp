.setcpu "65816"
.segment "CODE"
.org $DA40
map_control_0eda40:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
