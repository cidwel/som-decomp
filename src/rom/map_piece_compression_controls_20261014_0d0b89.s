.setcpu "65816"
.segment "CODE"
.org $0B89
map_control_0d0b89:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
