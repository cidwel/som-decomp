.setcpu "65816"
.segment "CODE"
.org $ABDF
map_control_0fabdf:
    .byte $E1 ; previous-row copy count
