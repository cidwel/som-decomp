.setcpu "65816"
.segment "CODE"
.org $6CDB
map_control_0c6cdb:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
