.setcpu "65816"
.segment "CODE"
.org $4F79
map_control_0f4f79:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
