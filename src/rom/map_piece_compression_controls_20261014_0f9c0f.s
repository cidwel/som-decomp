.setcpu "65816"
.segment "CODE"
.org $9C0F
map_control_0f9c0f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
