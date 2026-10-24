.setcpu "65816"
.segment "CODE"
.org $C78C
map_control_0fc78c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
