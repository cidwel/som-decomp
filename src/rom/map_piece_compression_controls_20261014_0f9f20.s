.setcpu "65816"
.segment "CODE"
.org $9F20
map_control_0f9f20:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
