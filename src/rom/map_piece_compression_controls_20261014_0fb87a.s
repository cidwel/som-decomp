.setcpu "65816"
.segment "CODE"
.org $B87A
map_control_0fb87a:
    .byte $CE ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $5B ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
