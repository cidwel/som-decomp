.setcpu "65816"
.segment "CODE"
.org $783D
map_control_0e783d:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
