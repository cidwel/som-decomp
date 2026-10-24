.setcpu "65816"
.segment "CODE"
.org $7827
map_control_0e7827:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
