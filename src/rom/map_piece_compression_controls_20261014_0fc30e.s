.setcpu "65816"
.segment "CODE"
.org $C30E
map_control_0fc30e:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
