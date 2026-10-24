.setcpu "65816"
.segment "CODE"
.org $0B76
map_control_0d0b76:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
