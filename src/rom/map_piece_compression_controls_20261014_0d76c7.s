.setcpu "65816"
.segment "CODE"
.org $76C7
map_control_0d76c7:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
