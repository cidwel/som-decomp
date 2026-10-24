.setcpu "65816"
.segment "CODE"
.org $2E28
map_control_0d2e28:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
