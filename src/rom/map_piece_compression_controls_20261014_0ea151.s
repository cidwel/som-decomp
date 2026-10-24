.setcpu "65816"
.segment "CODE"
.org $A151
map_control_0ea151:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
