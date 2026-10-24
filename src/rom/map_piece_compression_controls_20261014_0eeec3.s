.setcpu "65816"
.segment "CODE"
.org $EEC3
map_control_0eeec3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
