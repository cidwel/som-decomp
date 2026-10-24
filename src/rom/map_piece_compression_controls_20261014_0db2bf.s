.setcpu "65816"
.segment "CODE"
.org $B2BF
map_control_0db2bf:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
