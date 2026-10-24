.setcpu "65816"
.segment "CODE"
.org $CD70
map_control_0fcd70:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
