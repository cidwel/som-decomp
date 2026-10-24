.setcpu "65816"
.segment "CODE"
.org $CC4C
map_control_0fcc4c:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
