.setcpu "65816"
.segment "CODE"
.org $D166
map_control_0fd166:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
