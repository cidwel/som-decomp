.setcpu "65816"
.segment "CODE"
.org $FA23
map_control_0efa23:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
