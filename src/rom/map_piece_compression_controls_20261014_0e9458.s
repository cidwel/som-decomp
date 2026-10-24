.setcpu "65816"
.segment "CODE"
.org $9458
map_control_0e9458:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
