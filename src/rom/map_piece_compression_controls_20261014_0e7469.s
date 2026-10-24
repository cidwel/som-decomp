.setcpu "65816"
.segment "CODE"
.org $7469
map_control_0e7469:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
