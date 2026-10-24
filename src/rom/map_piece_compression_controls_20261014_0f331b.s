.setcpu "65816"
.segment "CODE"
.org $331B
map_control_0f331b:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
