.setcpu "65816"
.segment "CODE"
.org $C604
map_control_0fc604:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
