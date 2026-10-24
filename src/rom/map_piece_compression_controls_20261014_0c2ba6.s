.setcpu "65816"
.segment "CODE"
.org $2BA6
map_control_0c2ba6:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
