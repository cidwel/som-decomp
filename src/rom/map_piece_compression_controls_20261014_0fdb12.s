.setcpu "65816"
.segment "CODE"
.org $DB12
map_control_0fdb12:
    .byte $E1 ; previous-row copy count
