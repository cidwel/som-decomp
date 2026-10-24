.setcpu "65816"
.segment "CODE"
.org $5061
map_control_0e5061:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
