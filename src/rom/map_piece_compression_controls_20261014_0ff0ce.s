.setcpu "65816"
.segment "CODE"
.org $F0CE
map_control_0ff0ce:
    .byte $E1 ; previous-row copy count
