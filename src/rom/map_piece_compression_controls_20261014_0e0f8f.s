.setcpu "65816"
.segment "CODE"
.org $0F8F
map_control_0e0f8f:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
