.setcpu "65816"
.segment "CODE"
.org $9968
map_control_0e9968:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E1 ; previous-row copy count
