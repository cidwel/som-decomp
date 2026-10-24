.setcpu "65816"
.segment "CODE"
.org $F1F9
map_control_0ff1f9:
    .byte $E1 ; previous-row copy count
