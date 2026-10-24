.setcpu "65816"
.segment "CODE"
.org $85EC
map_control_0d85ec:
    .byte $E1 ; previous-row copy count
