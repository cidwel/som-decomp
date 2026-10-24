.setcpu "65816"
.segment "CODE"
.org $C1C5
map_control_0fc1c5:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
