.setcpu "65816"
.segment "CODE"
.org $5E05
map_control_0d5e05:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
