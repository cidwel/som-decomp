.setcpu "65816"
.segment "CODE"
.org $4B48
map_control_0f4b48:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
