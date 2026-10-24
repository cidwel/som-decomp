.setcpu "65816"
.segment "CODE"
.org $4970
map_control_0d4970:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
