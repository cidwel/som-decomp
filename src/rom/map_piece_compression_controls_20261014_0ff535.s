.setcpu "65816"
.segment "CODE"
.org $F535
map_control_0ff535:
    .byte $E1 ; previous-row copy count
