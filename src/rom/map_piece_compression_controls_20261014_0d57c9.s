.setcpu "65816"
.segment "CODE"
.org $57C9
map_control_0d57c9:
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
