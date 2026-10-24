.setcpu "65816"
.segment "CODE"
.org $ED0A
map_control_0ded0a:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
