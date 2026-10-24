.setcpu "65816"
.segment "CODE"
.org $34B4
map_control_0f34b4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
