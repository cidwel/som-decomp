.setcpu "65816"
.segment "CODE"
.org $C457
map_control_0dc457:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
