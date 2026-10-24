.setcpu "65816"
.segment "CODE"
.org $8432
map_control_0f8432:
    .byte $E1 ; previous-row copy count
