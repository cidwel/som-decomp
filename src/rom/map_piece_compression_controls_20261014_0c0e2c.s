.setcpu "65816"
.segment "CODE"
.org $0E2C
map_control_0c0e2c:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
