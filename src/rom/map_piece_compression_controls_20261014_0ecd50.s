.setcpu "65816"
.segment "CODE"
.org $CD50
map_control_0ecd50:
    .byte $E1 ; previous-row copy count
