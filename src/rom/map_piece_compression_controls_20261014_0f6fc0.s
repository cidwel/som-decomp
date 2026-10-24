.setcpu "65816"
.segment "CODE"
.org $6FC0
map_control_0f6fc0:
    .byte $E1 ; previous-row copy count
