.setcpu "65816"
.segment "CODE"
.org $4B31
map_control_0f4b31:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
