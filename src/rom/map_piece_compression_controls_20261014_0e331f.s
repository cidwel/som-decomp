.setcpu "65816"
.segment "CODE"
.org $331F
map_control_0e331f:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
