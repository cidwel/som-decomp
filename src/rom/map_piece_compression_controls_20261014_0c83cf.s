.setcpu "65816"
.segment "CODE"
.org $83CF
map_control_0c83cf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
