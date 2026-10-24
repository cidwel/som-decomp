.setcpu "65816"
.segment "CODE"
.org $8B10
map_control_0e8b10:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
