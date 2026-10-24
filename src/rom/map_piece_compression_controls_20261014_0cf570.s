.setcpu "65816"
.segment "CODE"
.org $F570
map_control_0cf570:
    .byte $E2 ; previous-row copy count
