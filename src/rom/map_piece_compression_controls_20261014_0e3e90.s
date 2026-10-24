.setcpu "65816"
.segment "CODE"
.org $3E90
map_control_0e3e90:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
