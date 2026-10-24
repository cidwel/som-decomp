.setcpu "65816"
.segment "CODE"
.org $C26E
map_control_0ec26e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
