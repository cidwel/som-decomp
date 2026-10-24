.setcpu "65816"
.segment "CODE"
.org $C896
map_control_0fc896:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
