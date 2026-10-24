.setcpu "65816"
.segment "CODE"
.org $F3F5
map_control_0ff3f5:
    .byte $E1 ; previous-row copy count
