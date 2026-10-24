.setcpu "65816"
.segment "CODE"
.org $2508
map_control_0f2508:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
