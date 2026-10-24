.setcpu "65816"
.segment "CODE"
.org $43F6
map_control_0c43f6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
