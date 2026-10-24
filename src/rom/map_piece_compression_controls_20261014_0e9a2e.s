.setcpu "65816"
.segment "CODE"
.org $9A2E
map_control_0e9a2e:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
