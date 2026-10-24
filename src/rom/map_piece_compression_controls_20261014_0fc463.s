.setcpu "65816"
.segment "CODE"
.org $C463
map_control_0fc463:
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
