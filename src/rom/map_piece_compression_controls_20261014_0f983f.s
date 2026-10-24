.setcpu "65816"
.segment "CODE"
.org $983F
map_control_0f983f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
