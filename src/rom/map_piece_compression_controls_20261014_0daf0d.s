.setcpu "65816"
.segment "CODE"
.org $AF0D
map_control_0daf0d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
