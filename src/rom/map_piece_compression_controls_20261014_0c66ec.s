.setcpu "65816"
.segment "CODE"
.org $66EC
map_control_0c66ec:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
