.setcpu "65816"
.segment "CODE"
.org $0625
map_control_0e0625:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
