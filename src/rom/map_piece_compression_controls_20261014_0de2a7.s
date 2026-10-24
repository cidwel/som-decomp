.setcpu "65816"
.segment "CODE"
.org $E2A7
map_control_0de2a7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
