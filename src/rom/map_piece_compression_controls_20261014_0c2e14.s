.setcpu "65816"
.segment "CODE"
.org $2E14
map_control_0c2e14:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
