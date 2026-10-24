.setcpu "65816"
.segment "CODE"
.org $F09A
map_control_0df09a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
