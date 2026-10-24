.setcpu "65816"
.segment "CODE"
.org $BA51
map_control_0dba51:
    .byte $E3 ; previous-row copy count
