.setcpu "65816"
.segment "CODE"
.org $18CC
map_control_0d18cc:
    .byte $E7 ; previous-row copy count
