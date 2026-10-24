.setcpu "65816"
.segment "CODE"
.org $5501
map_control_0e5501:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
