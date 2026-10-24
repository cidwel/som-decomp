.setcpu "65816"
.segment "CODE"
.org $79E8
map_control_0c79e8:
    .byte $F3 ; progressive-copy count
    .byte $E2 ; previous-row copy count
