.setcpu "65816"
.segment "CODE"
.org $2E3E
map_control_0d2e3e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
