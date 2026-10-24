.setcpu "65816"
.segment "CODE"
.org $ECD1
map_control_0eecd1:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
