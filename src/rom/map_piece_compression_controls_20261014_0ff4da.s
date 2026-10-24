.setcpu "65816"
.segment "CODE"
.org $F4DA
map_control_0ff4da:
    .byte $E5 ; previous-row copy count
