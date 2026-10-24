.setcpu "65816"
.segment "CODE"
.org $4A9F
map_control_0f4a9f:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
