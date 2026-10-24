.setcpu "65816"
.segment "CODE"
.org $B21A
map_control_0db21a:
    .byte $E1 ; previous-row copy count
