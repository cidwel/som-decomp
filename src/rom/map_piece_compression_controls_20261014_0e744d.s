.setcpu "65816"
.segment "CODE"
.org $744D
map_control_0e744d:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
