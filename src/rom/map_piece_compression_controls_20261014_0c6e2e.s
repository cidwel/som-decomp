.setcpu "65816"
.segment "CODE"
.org $6E2E
map_control_0c6e2e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
