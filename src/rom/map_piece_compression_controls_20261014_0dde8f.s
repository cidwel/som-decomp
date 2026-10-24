.setcpu "65816"
.segment "CODE"
.org $DE8F
map_control_0dde8f:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
