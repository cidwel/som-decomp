.setcpu "65816"
.segment "CODE"
.org $5444
map_control_0f5444:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
