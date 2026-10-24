.setcpu "65816"
.segment "CODE"
.org $BA23
map_control_0dba23:
    .byte $E6 ; previous-row copy count
