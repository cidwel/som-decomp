.setcpu "65816"
.segment "CODE"
.org $69F0
map_control_0f69f0:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
