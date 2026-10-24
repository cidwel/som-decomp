.setcpu "65816"
.segment "CODE"
.org $48B8
map_control_0c48b8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
