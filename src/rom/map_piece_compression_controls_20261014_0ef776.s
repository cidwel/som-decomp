.setcpu "65816"
.segment "CODE"
.org $F776
map_control_0ef776:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
