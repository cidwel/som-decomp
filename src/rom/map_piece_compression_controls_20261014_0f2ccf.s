.setcpu "65816"
.segment "CODE"
.org $2CCF
map_control_0f2ccf:
    .byte $E3 ; previous-row copy count
