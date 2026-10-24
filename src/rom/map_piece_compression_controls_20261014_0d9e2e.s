.setcpu "65816"
.segment "CODE"
.org $9E2E
map_control_0d9e2e:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
