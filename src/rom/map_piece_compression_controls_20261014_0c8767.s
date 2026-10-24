.setcpu "65816"
.segment "CODE"
.org $8767
map_control_0c8767:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
