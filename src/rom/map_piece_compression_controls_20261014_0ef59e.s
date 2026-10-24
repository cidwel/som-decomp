.setcpu "65816"
.segment "CODE"
.org $F59E
map_control_0ef59e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
