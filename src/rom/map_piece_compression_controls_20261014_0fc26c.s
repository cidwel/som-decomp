.setcpu "65816"
.segment "CODE"
.org $C26C
map_control_0fc26c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
