.setcpu "65816"
.segment "CODE"
.org $867F
map_control_0e867f:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E1 ; previous-row copy count
