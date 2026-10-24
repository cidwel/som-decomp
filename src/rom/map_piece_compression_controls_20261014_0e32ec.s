.setcpu "65816"
.segment "CODE"
.org $32EC
map_control_0e32ec:
    .byte $E2 ; previous-row copy count
