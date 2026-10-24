.setcpu "65816"
.segment "CODE"
.org $CA3A
map_control_0eca3a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
