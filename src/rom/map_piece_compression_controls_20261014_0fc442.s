.setcpu "65816"
.segment "CODE"
.org $C442
map_control_0fc442:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
