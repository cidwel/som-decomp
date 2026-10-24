.setcpu "65816"
.segment "CODE"
.org $9311
map_control_0e9311:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
