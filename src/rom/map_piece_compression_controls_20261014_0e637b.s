.setcpu "65816"
.segment "CODE"
.org $637B
map_control_0e637b:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
