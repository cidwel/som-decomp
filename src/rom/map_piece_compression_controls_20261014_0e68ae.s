.setcpu "65816"
.segment "CODE"
.org $68AE
map_control_0e68ae:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
