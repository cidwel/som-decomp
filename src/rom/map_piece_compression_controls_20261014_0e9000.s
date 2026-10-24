.setcpu "65816"
.segment "CODE"
.org $9000
map_control_0e9000:
    .byte $E2 ; previous-row copy count
