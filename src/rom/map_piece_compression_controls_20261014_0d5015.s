.setcpu "65816"
.segment "CODE"
.org $5015
map_control_0d5015:
    .byte $E1 ; previous-row copy count
