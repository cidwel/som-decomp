.setcpu "65816"
.segment "CODE"
.org $F241
map_control_0ff241:
    .byte $E1 ; previous-row copy count
