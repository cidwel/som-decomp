.setcpu "65816"
.segment "CODE"
.org $22C0
map_control_0e22c0:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
