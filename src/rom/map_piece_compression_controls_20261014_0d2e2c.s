.setcpu "65816"
.segment "CODE"
.org $2E2C
map_control_0d2e2c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
