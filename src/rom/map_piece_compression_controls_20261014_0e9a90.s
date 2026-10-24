.setcpu "65816"
.segment "CODE"
.org $9A90
map_control_0e9a90:
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
    .byte $E2 ; previous-row copy count
