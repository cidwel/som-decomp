.setcpu "65816"
.segment "CODE"
.org $B4B6
map_control_0db4b6:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
