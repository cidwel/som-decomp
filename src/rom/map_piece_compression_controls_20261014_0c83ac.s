.setcpu "65816"
.segment "CODE"
.org $83AC
map_control_0c83ac:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
