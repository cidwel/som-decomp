.setcpu "65816"
.segment "CODE"
.org $EBD2
map_control_0eebd2:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
