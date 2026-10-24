.setcpu "65816"
.segment "CODE"
.org $F2A3
map_control_0ef2a3:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
