.setcpu "65816"
.segment "CODE"
.org $CD2A
map_control_0dcd2a:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
