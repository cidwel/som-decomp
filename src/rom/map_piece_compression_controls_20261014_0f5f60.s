.setcpu "65816"
.segment "CODE"
.org $5F60
map_control_0f5f60:
    .byte $E2 ; previous-row copy count
