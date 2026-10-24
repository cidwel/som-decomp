.setcpu "65816"
.segment "CODE"
.org $57E9
map_control_0e57e9:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
