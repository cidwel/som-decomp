.setcpu "65816"
.segment "CODE"
.org $82CF
map_control_0d82cf:
    .byte $E2 ; previous-row copy count
