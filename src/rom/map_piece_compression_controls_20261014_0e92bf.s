.setcpu "65816"
.segment "CODE"
.org $92BF
map_control_0e92bf:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
