.setcpu "65816"
.segment "CODE"
.org $EBE7
map_control_0debe7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
