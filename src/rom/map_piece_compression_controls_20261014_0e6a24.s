.setcpu "65816"
.segment "CODE"
.org $6A24
map_control_0e6a24:
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
