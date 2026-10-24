.setcpu "65816"
.segment "CODE"
.org $2505
map_control_0d2505:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
