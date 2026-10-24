.setcpu "65816"
.segment "CODE"
.org $28B9
map_control_0e28b9:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
