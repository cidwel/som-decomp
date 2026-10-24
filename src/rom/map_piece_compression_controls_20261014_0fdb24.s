.setcpu "65816"
.segment "CODE"
.org $DB24
map_control_0fdb24:
    .byte $E1 ; previous-row copy count
