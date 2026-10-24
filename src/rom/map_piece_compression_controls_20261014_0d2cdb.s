.setcpu "65816"
.segment "CODE"
.org $2CDB
map_control_0d2cdb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
