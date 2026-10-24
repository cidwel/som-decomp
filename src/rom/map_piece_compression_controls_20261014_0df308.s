.setcpu "65816"
.segment "CODE"
.org $F308
map_control_0df308:
    .byte $E1 ; previous-row copy count
