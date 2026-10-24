.setcpu "65816"
.segment "CODE"
.org $8F42
map_control_0d8f42:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
