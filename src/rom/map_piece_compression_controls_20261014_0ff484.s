.setcpu "65816"
.segment "CODE"
.org $F484
map_control_0ff484:
    .byte $E1 ; previous-row copy count
