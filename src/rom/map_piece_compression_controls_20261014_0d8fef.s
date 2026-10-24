.setcpu "65816"
.segment "CODE"
.org $8FEF
map_control_0d8fef:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
