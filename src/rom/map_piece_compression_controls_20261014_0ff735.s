.setcpu "65816"
.segment "CODE"
.org $F735
map_control_0ff735:
    .byte $E6 ; previous-row copy count
