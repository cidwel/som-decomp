.setcpu "65816"
.segment "CODE"
.org $F964
map_control_0ff964:
    .byte $E6 ; previous-row copy count
