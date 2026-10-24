.setcpu "65816"
.segment "CODE"
.org $449F
map_control_0d449f:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
