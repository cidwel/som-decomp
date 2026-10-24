.setcpu "65816"
.segment "CODE"
.org $D3F1
map_control_0ed3f1:
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
