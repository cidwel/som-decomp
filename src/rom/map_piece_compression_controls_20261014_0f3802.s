.setcpu "65816"
.segment "CODE"
.org $3802
map_control_0f3802:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
