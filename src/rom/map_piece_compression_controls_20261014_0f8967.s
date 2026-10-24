.setcpu "65816"
.segment "CODE"
.org $8967
map_control_0f8967:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
