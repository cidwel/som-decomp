.setcpu "65816"
.segment "CODE"
.org $4D83
map_control_0e4d83:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
