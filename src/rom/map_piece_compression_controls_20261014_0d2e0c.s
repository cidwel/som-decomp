.setcpu "65816"
.segment "CODE"
.org $2E0C
map_control_0d2e0c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
