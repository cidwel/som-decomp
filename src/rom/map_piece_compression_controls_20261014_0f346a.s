.setcpu "65816"
.segment "CODE"
.org $346A
map_control_0f346a:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
