.setcpu "65816"
.segment "CODE"
.org $F3F3
map_control_0df3f3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
