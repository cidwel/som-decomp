.setcpu "65816"
.segment "CODE"
.org $ED04
map_control_0eed04:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
