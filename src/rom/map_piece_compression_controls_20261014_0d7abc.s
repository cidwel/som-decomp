.setcpu "65816"
.segment "CODE"
.org $7ABC
map_control_0d7abc:
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
