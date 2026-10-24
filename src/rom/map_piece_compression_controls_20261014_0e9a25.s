.setcpu "65816"
.segment "CODE"
.org $9A25
map_control_0e9a25:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $E1 ; previous-row copy count
