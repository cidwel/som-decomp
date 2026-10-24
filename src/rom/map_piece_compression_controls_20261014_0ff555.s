.setcpu "65816"
.segment "CODE"
.org $F555
map_control_0ff555:
    .byte $E5 ; previous-row copy count
