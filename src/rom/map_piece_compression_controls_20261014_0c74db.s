.setcpu "65816"
.segment "CODE"
.org $74DB
map_control_0c74db:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
