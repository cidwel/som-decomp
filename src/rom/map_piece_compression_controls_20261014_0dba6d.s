.setcpu "65816"
.segment "CODE"
.org $BA6D
map_control_0dba6d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
