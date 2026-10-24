.setcpu "65816"
.segment "CODE"
.org $66B4
map_control_0d66b4:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
