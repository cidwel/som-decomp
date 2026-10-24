.setcpu "65816"
.segment "CODE"
.org $7994
map_control_0f7994:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
