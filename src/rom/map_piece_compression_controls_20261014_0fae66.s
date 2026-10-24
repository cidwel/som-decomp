.setcpu "65816"
.segment "CODE"
.org $AE66
map_control_0fae66:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
