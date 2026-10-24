.setcpu "65816"
.segment "CODE"
.org $60FB
map_control_0e60fb:
    .byte $E1 ; previous-row copy count
