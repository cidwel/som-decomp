.setcpu "65816"
.segment "CODE"
.org $E718
map_control_0de718:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
