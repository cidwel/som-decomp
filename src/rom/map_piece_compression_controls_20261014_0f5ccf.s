.setcpu "65816"
.segment "CODE"
.org $5CCF
map_control_0f5ccf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
