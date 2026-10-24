.setcpu "65816"
.segment "CODE"
.org $C13C
map_control_0fc13c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
