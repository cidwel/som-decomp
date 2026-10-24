.setcpu "65816"
.segment "CODE"
.org $97B4
map_control_0d97b4:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E2 ; previous-row copy count
