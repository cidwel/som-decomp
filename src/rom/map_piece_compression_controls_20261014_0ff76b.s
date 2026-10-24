.setcpu "65816"
.segment "CODE"
.org $F76B
map_control_0ff76b:
    .byte $E6 ; previous-row copy count
