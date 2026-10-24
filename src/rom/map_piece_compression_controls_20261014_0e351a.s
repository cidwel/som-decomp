.setcpu "65816"
.segment "CODE"
.org $351A
map_control_0e351a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
