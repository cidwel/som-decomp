.setcpu "65816"
.segment "CODE"
.org $3A18
map_control_0e3a18:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
