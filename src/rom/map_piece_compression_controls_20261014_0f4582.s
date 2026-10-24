.setcpu "65816"
.segment "CODE"
.org $4582
map_control_0f4582:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
