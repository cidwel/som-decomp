.setcpu "65816"
.segment "CODE"
.org $C0DC
map_control_0fc0dc:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
