.setcpu "65816"
.segment "CODE"
.org $60BF
map_control_0c60bf:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
