.setcpu "65816"
.segment "CODE"
.org $6CFE
map_control_0c6cfe:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
