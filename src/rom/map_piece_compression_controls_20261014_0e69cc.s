.setcpu "65816"
.segment "CODE"
.org $69CC
map_control_0e69cc:
    .byte $E2 ; previous-row copy count
