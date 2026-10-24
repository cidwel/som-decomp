.setcpu "65816"
.segment "CODE"
.org $E61C
map_control_0fe61c:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
