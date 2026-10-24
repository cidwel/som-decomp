.setcpu "65816"
.segment "CODE"
.org $CB6D
map_control_0fcb6d:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
