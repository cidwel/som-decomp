.setcpu "65816"
.segment "CODE"
.org $72DB
map_control_0c72db:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
