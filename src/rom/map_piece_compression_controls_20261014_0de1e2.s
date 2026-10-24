.setcpu "65816"
.segment "CODE"
.org $E1E2
map_control_0de1e2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
