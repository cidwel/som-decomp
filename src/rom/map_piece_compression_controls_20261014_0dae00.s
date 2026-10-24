.setcpu "65816"
.segment "CODE"
.org $AE00
map_control_0dae00:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
