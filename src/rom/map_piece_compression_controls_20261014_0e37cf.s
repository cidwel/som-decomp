.setcpu "65816"
.segment "CODE"
.org $37CF
map_control_0e37cf:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
