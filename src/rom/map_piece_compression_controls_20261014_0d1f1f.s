.setcpu "65816"
.segment "CODE"
.org $1F1F
map_control_0d1f1f:
    .byte $E6 ; previous-row copy count
