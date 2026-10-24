.setcpu "65816"
.segment "CODE"
.org $BC69
map_control_0fbc69:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
