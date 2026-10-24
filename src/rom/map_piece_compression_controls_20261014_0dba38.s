.setcpu "65816"
.segment "CODE"
.org $BA38
map_control_0dba38:
    .byte $E1 ; previous-row copy count
