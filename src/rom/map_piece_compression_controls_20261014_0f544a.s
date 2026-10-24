.setcpu "65816"
.segment "CODE"
.org $544A
map_control_0f544a:
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
