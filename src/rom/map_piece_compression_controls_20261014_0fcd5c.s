.setcpu "65816"
.segment "CODE"
.org $CD5C
map_control_0fcd5c:
    .byte $E3 ; previous-row copy count
