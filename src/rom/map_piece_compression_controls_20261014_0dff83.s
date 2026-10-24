.setcpu "65816"
.segment "CODE"
.org $FF83
map_control_0dff83:
    .byte $E2 ; previous-row copy count
