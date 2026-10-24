.setcpu "65816"
.segment "CODE"
.org $123D
map_control_0e123d:
    .byte $E2 ; previous-row copy count
