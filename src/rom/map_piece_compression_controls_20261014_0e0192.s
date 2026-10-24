.setcpu "65816"
.segment "CODE"
.org $0192
map_control_0e0192:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
