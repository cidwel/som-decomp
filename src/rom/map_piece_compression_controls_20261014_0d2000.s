.setcpu "65816"
.segment "CODE"
.org $2000
map_control_0d2000:
    .byte $E2 ; previous-row copy count
