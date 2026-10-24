.setcpu "65816"
.segment "CODE"
.org $2E9A
map_control_0d2e9a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
