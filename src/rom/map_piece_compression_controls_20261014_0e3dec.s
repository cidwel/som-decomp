.setcpu "65816"
.segment "CODE"
.org $3DEC
map_control_0e3dec:
    .byte $E2 ; previous-row copy count
