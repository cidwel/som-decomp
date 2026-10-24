.setcpu "65816"
.segment "CODE"
.org $4014
map_control_0f4014:
    .byte $E0 ; previous-row copy escape
    .byte $C0 ; row-distance/count
