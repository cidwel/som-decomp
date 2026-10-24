.setcpu "65816"
.segment "CODE"
.org $96C4
map_control_0e96c4:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
