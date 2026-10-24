.setcpu "65816"
.segment "CODE"
.org $543A
map_control_0d543a:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
