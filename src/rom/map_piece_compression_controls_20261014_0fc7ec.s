.setcpu "65816"
.segment "CODE"
.org $C7EC
map_control_0fc7ec:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
