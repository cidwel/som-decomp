.setcpu "65816"
.segment "CODE"
.org $839D
map_control_0c839d:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
