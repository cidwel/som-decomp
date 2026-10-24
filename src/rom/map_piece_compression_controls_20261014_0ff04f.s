.setcpu "65816"
.segment "CODE"
.org $F04F
map_control_0ff04f:
    .byte $E1 ; previous-row copy count
