.setcpu "65816"
.segment "CODE"
.org $F96C
map_control_0df96c:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F7 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
