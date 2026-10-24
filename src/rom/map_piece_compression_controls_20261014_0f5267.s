.setcpu "65816"
.segment "CODE"
.org $5267
map_control_0f5267:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
