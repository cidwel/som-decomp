.setcpu "65816"
.segment "CODE"
.org $51D2
map_control_0d51d2:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
