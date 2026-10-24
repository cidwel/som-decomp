.setcpu "65816"
.segment "CODE"
.org $3FAE
map_control_0d3fae:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
