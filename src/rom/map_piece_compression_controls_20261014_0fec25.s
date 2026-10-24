.setcpu "65816"
.segment "CODE"
.org $EC25
map_control_0fec25:
    .byte $E2 ; previous-row copy count
