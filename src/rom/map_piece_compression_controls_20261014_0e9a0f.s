.setcpu "65816"
.segment "CODE"
.org $9A0F
map_control_0e9a0f:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $E2 ; previous-row copy count
