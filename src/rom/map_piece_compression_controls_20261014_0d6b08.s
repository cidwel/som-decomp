.setcpu "65816"
.segment "CODE"
.org $6B08
map_control_0d6b08:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E1 ; previous-row copy count
