.setcpu "65816"
.segment "CODE"
.org $ABE6
map_control_0fabe6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
