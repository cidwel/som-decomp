.setcpu "65816"
.segment "CODE"
.org $4AC6
map_control_0f4ac6:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
