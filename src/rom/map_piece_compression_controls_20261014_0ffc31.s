.setcpu "65816"
.segment "CODE"
.org $FC31
map_control_0ffc31:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
