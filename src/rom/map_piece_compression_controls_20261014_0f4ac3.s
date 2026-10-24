.setcpu "65816"
.segment "CODE"
.org $4AC3
map_control_0f4ac3:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
