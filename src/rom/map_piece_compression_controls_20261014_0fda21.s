.setcpu "65816"
.segment "CODE"
.org $DA21
map_control_0fda21:
    .byte $E1 ; previous-row copy count
