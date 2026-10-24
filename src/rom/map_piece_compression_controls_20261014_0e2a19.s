.setcpu "65816"
.segment "CODE"
.org $2A19
map_control_0e2a19:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E2 ; previous-row copy count
