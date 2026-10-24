.setcpu "65816"
.segment "CODE"
.org $08FC
map_control_0f08fc:
    .byte $E5 ; previous-row copy count
