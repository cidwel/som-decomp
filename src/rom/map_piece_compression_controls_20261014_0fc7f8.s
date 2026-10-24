.setcpu "65816"
.segment "CODE"
.org $C7F8
map_control_0fc7f8:
    .byte $CA ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
