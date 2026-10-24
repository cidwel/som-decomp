.setcpu "65816"
.segment "CODE"
.org $7A5A
map_control_0c7a5a:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
