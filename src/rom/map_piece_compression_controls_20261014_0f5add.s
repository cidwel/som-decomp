.setcpu "65816"
.segment "CODE"
.org $5ADD
map_control_0f5add:
    .byte $E2 ; previous-row copy count
