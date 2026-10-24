.setcpu "65816"
.segment "CODE"
.org $7578
map_control_0d7578:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
