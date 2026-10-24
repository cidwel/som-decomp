.setcpu "65816"
.segment "CODE"
.org $50AF
map_control_0f50af:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
