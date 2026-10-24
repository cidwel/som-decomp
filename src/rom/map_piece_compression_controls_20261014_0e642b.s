.setcpu "65816"
.segment "CODE"
.org $642B
map_control_0e642b:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
