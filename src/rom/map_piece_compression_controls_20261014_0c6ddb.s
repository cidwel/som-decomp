.setcpu "65816"
.segment "CODE"
.org $6DDB
map_control_0c6ddb:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
