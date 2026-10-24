.setcpu "65816"
.segment "CODE"
.org $F593
map_control_0ff593:
    .byte $E1 ; previous-row copy count
