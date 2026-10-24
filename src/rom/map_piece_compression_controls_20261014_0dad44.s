.setcpu "65816"
.segment "CODE"
.org $AD44
map_control_0dad44:
    .byte $E0 ; previous-row copy escape
    .byte $D3 ; row-distance/count
