.setcpu "65816"
.segment "CODE"
.org $C4F4
map_control_0ec4f4:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
