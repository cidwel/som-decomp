.setcpu "65816"
.segment "CODE"
.org $AE63
map_control_0fae63:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
