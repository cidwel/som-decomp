.setcpu "65816"
.segment "CODE"
.org $29E1
map_control_0d29e1:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
