.setcpu "65816"
.segment "CODE"
.org $818E
map_control_0f818e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
