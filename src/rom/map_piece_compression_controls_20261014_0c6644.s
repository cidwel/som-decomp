.setcpu "65816"
.segment "CODE"
.org $6644
map_control_0c6644:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
