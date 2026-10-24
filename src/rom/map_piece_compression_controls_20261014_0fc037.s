.setcpu "65816"
.segment "CODE"
.org $C037
map_control_0fc037:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
