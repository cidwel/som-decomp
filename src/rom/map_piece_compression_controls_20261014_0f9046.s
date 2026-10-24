.setcpu "65816"
.segment "CODE"
.org $9046
map_control_0f9046:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
