.setcpu "65816"
.segment "CODE"
.org $B901
map_control_0db901:
    .byte $E7 ; previous-row copy count
