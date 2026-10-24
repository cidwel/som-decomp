.setcpu "65816"
.segment "CODE"
.org $C8B2
map_control_0fc8b2:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
