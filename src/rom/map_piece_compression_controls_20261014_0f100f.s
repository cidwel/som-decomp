.setcpu "65816"
.segment "CODE"
.org $100F
map_control_0f100f:
    .byte $E3 ; previous-row copy count
