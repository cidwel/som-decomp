.setcpu "65816"
.segment "CODE"
.org $E41A
map_control_0de41a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
