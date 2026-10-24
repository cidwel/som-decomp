.setcpu "65816"
.segment "CODE"
.org $66B6
map_control_0f66b6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
