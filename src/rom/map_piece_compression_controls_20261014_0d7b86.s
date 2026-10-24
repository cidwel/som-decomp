.setcpu "65816"
.segment "CODE"
.org $7B86
map_control_0d7b86:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
