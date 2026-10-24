.setcpu "65816"
.segment "CODE"
.org $CE15
map_control_0dce15:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
