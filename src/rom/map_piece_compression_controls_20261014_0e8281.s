.setcpu "65816"
.segment "CODE"
.org $8281
map_control_0e8281:
    .byte $E1 ; previous-row copy count
