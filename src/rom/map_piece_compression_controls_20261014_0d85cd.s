.setcpu "65816"
.segment "CODE"
.org $85CD
map_control_0d85cd:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
