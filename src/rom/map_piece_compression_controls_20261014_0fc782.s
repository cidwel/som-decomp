.setcpu "65816"
.segment "CODE"
.org $C782
map_control_0fc782:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
