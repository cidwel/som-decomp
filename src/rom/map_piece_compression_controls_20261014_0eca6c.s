.setcpu "65816"
.segment "CODE"
.org $CA6C
map_control_0eca6c:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
