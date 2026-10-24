.setcpu "65816"
.segment "CODE"
.org $B53A
map_control_0fb53a:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
