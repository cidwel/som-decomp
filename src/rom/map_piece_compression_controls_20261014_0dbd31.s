.setcpu "65816"
.segment "CODE"
.org $BD31
map_control_0dbd31:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
