.setcpu "65816"
.segment "CODE"
.org $C16A
map_control_0fc16a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
