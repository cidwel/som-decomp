.setcpu "65816"
.segment "CODE"
.org $1DBF
map_control_0f1dbf:
    .byte $E2 ; previous-row copy count
