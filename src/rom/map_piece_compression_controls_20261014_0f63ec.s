.setcpu "65816"
.segment "CODE"
.org $63EC
map_control_0f63ec:
    .byte $E2 ; previous-row copy count
