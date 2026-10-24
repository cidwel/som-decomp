.setcpu "65816"
.segment "CODE"
.org $28B1
map_control_0d28b1:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
