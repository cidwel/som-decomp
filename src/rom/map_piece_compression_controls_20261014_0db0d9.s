.setcpu "65816"
.segment "CODE"
.org $B0D9
map_control_0db0d9:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
