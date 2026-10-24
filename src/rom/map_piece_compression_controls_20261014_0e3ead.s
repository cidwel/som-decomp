.setcpu "65816"
.segment "CODE"
.org $3EAD
map_control_0e3ead:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
