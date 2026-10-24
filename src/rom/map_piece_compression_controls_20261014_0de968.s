.setcpu "65816"
.segment "CODE"
.org $E968
map_control_0de968:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
