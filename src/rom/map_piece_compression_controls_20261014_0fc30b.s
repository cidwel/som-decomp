.setcpu "65816"
.segment "CODE"
.org $C30B
map_control_0fc30b:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
