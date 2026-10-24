.setcpu "65816"
.segment "CODE"
.org $678E
map_control_0d678e:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
