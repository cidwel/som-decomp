.setcpu "65816"
.segment "CODE"
.org $8406
map_control_0c8406:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
