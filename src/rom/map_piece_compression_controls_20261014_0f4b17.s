.setcpu "65816"
.segment "CODE"
.org $4B17
map_control_0f4b17:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
