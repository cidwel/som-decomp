.setcpu "65816"
.segment "CODE"
.org $3CDB
map_control_0f3cdb:
    .byte $E7 ; previous-row copy count
