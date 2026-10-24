.setcpu "65816"
.segment "CODE"
.org $C702
map_control_0fc702:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
