.setcpu "65816"
.segment "CODE"
.org $B750
map_control_0db750:
    .byte $E3 ; previous-row copy count
