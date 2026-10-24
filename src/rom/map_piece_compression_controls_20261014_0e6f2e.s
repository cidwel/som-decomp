.setcpu "65816"
.segment "CODE"
.org $6F2E
map_control_0e6f2e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
