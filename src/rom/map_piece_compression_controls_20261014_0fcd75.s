.setcpu "65816"
.segment "CODE"
.org $CD75
map_control_0fcd75:
    .byte $E5 ; previous-row copy count
