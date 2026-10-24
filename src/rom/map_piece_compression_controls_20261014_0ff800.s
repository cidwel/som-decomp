.setcpu "65816"
.segment "CODE"
.org $F800
map_control_0ff800:
    .byte $E6 ; previous-row copy count
