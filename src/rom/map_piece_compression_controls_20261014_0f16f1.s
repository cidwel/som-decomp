.setcpu "65816"
.segment "CODE"
.org $16F1
map_control_0f16f1:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
