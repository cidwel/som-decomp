.setcpu "65816"
.segment "CODE"
.org $6FA2
map_control_0d6fa2:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
