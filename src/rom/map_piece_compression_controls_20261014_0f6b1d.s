.setcpu "65816"
.segment "CODE"
.org $6B1D
map_control_0f6b1d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
