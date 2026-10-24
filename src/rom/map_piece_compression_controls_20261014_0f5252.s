.setcpu "65816"
.segment "CODE"
.org $5252
map_control_0f5252:
    .byte $E1 ; previous-row copy count
