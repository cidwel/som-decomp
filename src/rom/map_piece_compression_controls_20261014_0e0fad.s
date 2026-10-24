.setcpu "65816"
.segment "CODE"
.org $0FAD
map_control_0e0fad:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
