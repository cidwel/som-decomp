.setcpu "65816"
.segment "CODE"
.org $371D
map_control_0d371d:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
