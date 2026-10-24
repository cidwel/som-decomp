.setcpu "65816"
.segment "CODE"
.org $AF55
map_control_0daf55:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
