.setcpu "65816"
.segment "CODE"
.org $50C4
map_control_0f50c4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
