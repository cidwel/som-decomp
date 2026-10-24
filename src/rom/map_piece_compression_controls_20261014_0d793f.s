.setcpu "65816"
.segment "CODE"
.org $793F
map_control_0d793f:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
