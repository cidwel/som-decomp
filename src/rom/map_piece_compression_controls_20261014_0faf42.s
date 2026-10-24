.setcpu "65816"
.segment "CODE"
.org $AF42
map_control_0faf42:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
