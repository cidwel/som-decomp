.setcpu "65816"
.segment "CODE"
.org $2E61
map_control_0c2e61:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
