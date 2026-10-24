.setcpu "65816"
.segment "CODE"
.org $70EC
map_control_0d70ec:
    .byte $E2 ; previous-row copy count
