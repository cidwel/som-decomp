.setcpu "65816"
.segment "CODE"
.org $5F40
map_control_0f5f40:
    .byte $E2 ; previous-row copy count
