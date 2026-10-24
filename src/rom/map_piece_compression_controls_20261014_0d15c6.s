.setcpu "65816"
.segment "CODE"
.org $15C6
map_control_0d15c6:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
