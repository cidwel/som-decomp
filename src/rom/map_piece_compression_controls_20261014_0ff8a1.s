.setcpu "65816"
.segment "CODE"
.org $F8A1
map_control_0ff8a1:
    .byte $E2 ; previous-row copy count
