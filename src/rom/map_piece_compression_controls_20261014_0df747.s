.setcpu "65816"
.segment "CODE"
.org $F747
map_control_0df747:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
