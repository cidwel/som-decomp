.setcpu "65816"
.segment "CODE"
.org $8970
map_control_0e8970:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
