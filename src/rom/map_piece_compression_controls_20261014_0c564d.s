.setcpu "65816"
.segment "CODE"
.org $564D
map_control_0c564d:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
