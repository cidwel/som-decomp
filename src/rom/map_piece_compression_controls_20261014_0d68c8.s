.setcpu "65816"
.segment "CODE"
.org $68C8
map_control_0d68c8:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
