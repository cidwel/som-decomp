.setcpu "65816"
.segment "CODE"
.org $4A22
map_control_0f4a22:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
