.setcpu "65816"
.segment "CODE"
.org $C402
map_control_0fc402:
    .byte $E0 ; previous-row copy escape
    .byte $DD ; row-distance/count
