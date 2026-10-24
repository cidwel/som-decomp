.setcpu "65816"
.segment "CODE"
.org $05A5
map_control_0e05a5:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
