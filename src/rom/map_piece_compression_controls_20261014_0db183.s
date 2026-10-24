.setcpu "65816"
.segment "CODE"
.org $B183
map_control_0db183:
    .byte $E2 ; previous-row copy count
