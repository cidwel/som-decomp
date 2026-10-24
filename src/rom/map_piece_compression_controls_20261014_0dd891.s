.setcpu "65816"
.segment "CODE"
.org $D891
map_control_0dd891:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
