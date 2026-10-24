.setcpu "65816"
.segment "CODE"
.org $9A18
map_control_0e9a18:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
