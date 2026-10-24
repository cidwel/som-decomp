.setcpu "65816"
.segment "CODE"
.org $E61A
map_control_0de61a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
