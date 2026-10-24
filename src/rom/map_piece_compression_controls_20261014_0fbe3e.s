.setcpu "65816"
.segment "CODE"
.org $BE3E
map_control_0fbe3e:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
