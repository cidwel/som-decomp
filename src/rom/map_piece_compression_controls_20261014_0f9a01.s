.setcpu "65816"
.segment "CODE"
.org $9A01
map_control_0f9a01:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
