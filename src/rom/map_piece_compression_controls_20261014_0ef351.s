.setcpu "65816"
.segment "CODE"
.org $F351
map_control_0ef351:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
