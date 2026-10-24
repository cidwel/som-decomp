.setcpu "65816"
.segment "CODE"
.org $C24E
map_control_0fc24e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
