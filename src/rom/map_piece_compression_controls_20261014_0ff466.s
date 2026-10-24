.setcpu "65816"
.segment "CODE"
.org $F466
map_control_0ff466:
    .byte $E2 ; previous-row copy count
