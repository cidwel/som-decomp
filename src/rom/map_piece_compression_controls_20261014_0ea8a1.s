.setcpu "65816"
.segment "CODE"
.org $A8A1
map_control_0ea8a1:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
