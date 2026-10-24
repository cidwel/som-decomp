.setcpu "65816"
.segment "CODE"
.org $9CAC
map_control_0e9cac:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $BF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
