.setcpu "65816"
.segment "CODE"
.org $F998
map_control_0ff998:
    .byte $E1 ; previous-row copy count
