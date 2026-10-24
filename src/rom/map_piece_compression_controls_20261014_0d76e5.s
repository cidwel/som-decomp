.setcpu "65816"
.segment "CODE"
.org $76E5
map_control_0d76e5:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
