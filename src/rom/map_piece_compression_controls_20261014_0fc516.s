.setcpu "65816"
.segment "CODE"
.org $C516
map_control_0fc516:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
