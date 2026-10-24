.setcpu "65816"
.segment "CODE"
.org $4CDB
map_control_0f4cdb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
