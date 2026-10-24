.setcpu "65816"
.segment "CODE"
.org $785A
map_control_0c785a:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
