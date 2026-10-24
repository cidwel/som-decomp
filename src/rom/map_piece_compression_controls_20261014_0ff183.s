.setcpu "65816"
.segment "CODE"
.org $F183
map_control_0ff183:
    .byte $E1 ; previous-row copy count
