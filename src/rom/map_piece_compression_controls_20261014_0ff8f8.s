.setcpu "65816"
.segment "CODE"
.org $F8F8
map_control_0ff8f8:
    .byte $E2 ; previous-row copy count
