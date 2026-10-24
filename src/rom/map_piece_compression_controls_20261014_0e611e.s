.setcpu "65816"
.segment "CODE"
.org $611E
map_control_0e611e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
