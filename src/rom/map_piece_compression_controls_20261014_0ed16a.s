.setcpu "65816"
.segment "CODE"
.org $D16A
map_control_0ed16a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
