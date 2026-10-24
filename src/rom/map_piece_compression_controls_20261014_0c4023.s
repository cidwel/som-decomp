.setcpu "65816"
.segment "CODE"
.org $4023
map_control_0c4023:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
