.setcpu "65816"
.segment "CODE"
.org $9BDE
map_control_0f9bde:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
