.setcpu "65816"
.segment "CODE"
.org $C6D0
map_control_0fc6d0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
