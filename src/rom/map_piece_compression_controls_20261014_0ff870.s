.setcpu "65816"
.segment "CODE"
.org $F870
map_control_0ff870:
    .byte $D5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
