.setcpu "65816"
.segment "CODE"
.org $5890
map_control_0e5890:
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
