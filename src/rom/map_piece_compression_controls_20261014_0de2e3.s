.setcpu "65816"
.segment "CODE"
.org $E2E3
map_control_0de2e3:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
