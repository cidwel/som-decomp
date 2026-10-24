.setcpu "65816"
.segment "CODE"
.org $1180
map_control_0d1180:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E2 ; previous-row copy count
