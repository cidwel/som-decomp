.setcpu "65816"
.segment "CODE"
.org $B15D
map_control_0fb15d:
    .byte $E1 ; previous-row copy count
