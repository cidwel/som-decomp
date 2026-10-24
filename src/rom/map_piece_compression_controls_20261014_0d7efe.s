.setcpu "65816"
.segment "CODE"
.org $7EFE
map_control_0d7efe:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
