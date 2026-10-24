.setcpu "65816"
.segment "CODE"
.org $2AE8
map_control_0f2ae8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
