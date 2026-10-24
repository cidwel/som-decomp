.setcpu "65816"
.segment "CODE"
.org $F284
map_control_0cf284:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
