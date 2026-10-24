.setcpu "65816"
.segment "CODE"
.org $450C
map_control_0e450c:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
