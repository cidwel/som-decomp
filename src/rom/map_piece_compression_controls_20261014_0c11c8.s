.setcpu "65816"
.segment "CODE"
.org $11C8
map_control_0c11c8:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
