.setcpu "65816"
.segment "CODE"
.org $7E16
map_control_0f7e16:
    .byte $E2 ; previous-row copy count
