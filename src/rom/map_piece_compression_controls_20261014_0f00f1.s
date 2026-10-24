.setcpu "65816"
.segment "CODE"
.org $00F1
map_control_0f00f1:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
