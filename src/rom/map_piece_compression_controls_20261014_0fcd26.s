.setcpu "65816"
.segment "CODE"
.org $CD26
map_control_0fcd26:
    .byte $E2 ; previous-row copy count
