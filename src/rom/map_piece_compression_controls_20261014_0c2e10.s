.setcpu "65816"
.segment "CODE"
.org $2E10
map_control_0c2e10:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
