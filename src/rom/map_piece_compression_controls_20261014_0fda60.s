.setcpu "65816"
.segment "CODE"
.org $DA60
map_control_0fda60:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
