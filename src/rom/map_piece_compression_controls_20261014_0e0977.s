.setcpu "65816"
.segment "CODE"
.org $0977
map_control_0e0977:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
