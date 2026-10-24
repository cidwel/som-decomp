.setcpu "65816"
.segment "CODE"
.org $DD2E
map_control_0edd2e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
