.setcpu "65816"
.segment "CODE"
.org $792B
map_control_0f792b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
