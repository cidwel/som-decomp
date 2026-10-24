.setcpu "65816"
.segment "CODE"
.org $1869
map_control_0f1869:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
