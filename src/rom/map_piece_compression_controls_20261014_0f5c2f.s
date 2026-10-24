.setcpu "65816"
.segment "CODE"
.org $5C2F
map_control_0f5c2f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
