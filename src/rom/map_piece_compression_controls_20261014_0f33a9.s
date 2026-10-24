.setcpu "65816"
.segment "CODE"
.org $33A9
map_control_0f33a9:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
