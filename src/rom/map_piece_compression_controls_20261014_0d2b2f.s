.setcpu "65816"
.segment "CODE"
.org $2B2F
map_control_0d2b2f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
