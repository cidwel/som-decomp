.setcpu "65816"
.segment "CODE"
.org $8468
map_control_0e8468:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
