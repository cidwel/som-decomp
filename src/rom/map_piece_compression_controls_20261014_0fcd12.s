.setcpu "65816"
.segment "CODE"
.org $CD12
map_control_0fcd12:
    .byte $E1 ; previous-row copy count
