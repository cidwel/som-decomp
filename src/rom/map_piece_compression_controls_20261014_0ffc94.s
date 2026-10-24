.setcpu "65816"
.segment "CODE"
.org $FC94
map_control_0ffc94:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
