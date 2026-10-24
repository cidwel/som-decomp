.setcpu "65816"
.segment "CODE"
.org $C65B
map_control_0fc65b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
