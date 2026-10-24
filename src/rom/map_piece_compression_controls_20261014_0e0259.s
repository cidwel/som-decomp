.setcpu "65816"
.segment "CODE"
.org $0259
map_control_0e0259:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
