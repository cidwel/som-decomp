.setcpu "65816"
.segment "CODE"
.org $CD57
map_control_0fcd57:
    .byte $E3 ; previous-row copy count
