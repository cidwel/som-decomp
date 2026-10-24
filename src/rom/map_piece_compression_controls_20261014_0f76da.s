.setcpu "65816"
.segment "CODE"
.org $76DA
map_control_0f76da:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
