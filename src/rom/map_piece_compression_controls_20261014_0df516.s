.setcpu "65816"
.segment "CODE"
.org $F516
map_control_0df516:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
