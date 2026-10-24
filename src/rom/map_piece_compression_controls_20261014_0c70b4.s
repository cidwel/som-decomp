.setcpu "65816"
.segment "CODE"
.org $70B4
map_control_0c70b4:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E1 ; previous-row copy count
