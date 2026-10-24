.setcpu "65816"
.segment "CODE"
.org $7338
map_control_0e7338:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
