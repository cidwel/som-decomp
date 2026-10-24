.setcpu "65816"
.segment "CODE"
.org $F159
map_control_0ff159:
    .byte $E1 ; previous-row copy count
