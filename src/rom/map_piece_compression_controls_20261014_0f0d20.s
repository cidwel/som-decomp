.setcpu "65816"
.segment "CODE"
.org $0D20
map_control_0f0d20:
    .byte $E2 ; previous-row copy count
