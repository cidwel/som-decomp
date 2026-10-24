.setcpu "65816"
.segment "CODE"
.org $D238
map_control_0dd238:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
