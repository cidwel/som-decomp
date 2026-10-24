.setcpu "65816"
.segment "CODE"
.org $0F96
map_control_0d0f96:
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
