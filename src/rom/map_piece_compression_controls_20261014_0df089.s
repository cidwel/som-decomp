.setcpu "65816"
.segment "CODE"
.org $F089
map_control_0df089:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
