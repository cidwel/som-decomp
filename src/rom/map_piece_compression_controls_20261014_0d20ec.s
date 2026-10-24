.setcpu "65816"
.segment "CODE"
.org $20EC
map_control_0d20ec:
    .byte $E3 ; previous-row copy count
