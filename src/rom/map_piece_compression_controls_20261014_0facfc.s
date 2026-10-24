.setcpu "65816"
.segment "CODE"
.org $ACFC
map_control_0facfc:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
