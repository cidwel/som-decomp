.setcpu "65816"
.segment "CODE"
.org $C790
map_control_0fc790:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
