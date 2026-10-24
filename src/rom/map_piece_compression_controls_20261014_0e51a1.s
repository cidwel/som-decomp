.setcpu "65816"
.segment "CODE"
.org $51A1
map_control_0e51a1:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
