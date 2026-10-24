.setcpu "65816"
.segment "CODE"
.org $5749
map_control_0e5749:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
