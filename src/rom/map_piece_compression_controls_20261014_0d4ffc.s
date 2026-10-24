.setcpu "65816"
.segment "CODE"
.org $4FFC
map_control_0d4ffc:
    .byte $E1 ; previous-row copy count
