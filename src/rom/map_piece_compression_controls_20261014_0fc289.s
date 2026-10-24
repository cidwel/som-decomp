.setcpu "65816"
.segment "CODE"
.org $C289
map_control_0fc289:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
