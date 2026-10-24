.setcpu "65816"
.segment "CODE"
.org $0798
map_control_0e0798:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
