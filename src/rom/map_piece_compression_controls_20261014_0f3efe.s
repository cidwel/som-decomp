.setcpu "65816"
.segment "CODE"
.org $3EFE
map_control_0f3efe:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
