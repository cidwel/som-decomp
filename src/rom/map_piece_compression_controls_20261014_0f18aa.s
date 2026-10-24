.setcpu "65816"
.segment "CODE"
.org $18AA
map_control_0f18aa:
    .byte $E2 ; previous-row copy count
